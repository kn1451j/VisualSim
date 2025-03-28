import gaussian_splatting
from gaussian_splatting.scene.gaussian_model import GaussianModel
from gaussian_splatting.arguments import PipelineParams
from gaussian_splatting.scene.cameras import MiniCam
from gaussian_splatting.utils.graphics_utils import getWorld2View, getProjectionMatrix

from argparse import ArgumentParser, Namespace
import torch
import cv2
import json
import numpy as np
from plyfile import PlyData

class Render:
    def __init__(self, cfg_base_path, save_path):
        args = ArgumentParser(description="Testing script parameters")
        self.pipeline = self._load_pipeline(args, cfg_base_path+"/cfg_args")
        self.gaussians = self._load_gaussian_model(cfg_base_path+"/point_cloud/iteration_30000/point_cloud.ply")
        self.save_path = save_path
        
        # initial Gaussian render
        self.camera = self._create_camera_from_json(cfg_base_path+"/cameras.json", cam_idx=0)
        self.render_gaussians()

    def _create_camera_from_json(self, json_path, cam_idx = 0):
        with open(json_path, 'r') as file:
            cam = json.load(file)[cam_idx]
            width = cam["width"]
            height = cam["height"]
            fovy = cam["fy"]
            fovx = cam["fx"]
            R = np.array(cam["rotation"])
            T = np.array(cam["position"])
            znear = 500.0
            zfar = 100.5

            world_view_transform = torch.tensor(getWorld2View(R, T)).transpose(0, 1).cuda()
            projection_matrix = getProjectionMatrix(znear=znear, zfar=zfar, fovX=fovx, fovY=fovy).transpose(0,1).cuda()
            full_proj_transform = (world_view_transform.unsqueeze(0).bmm(projection_matrix.unsqueeze(0))).squeeze(0)
            camera = MiniCam(width, height, fovy, fovx, znear, zfar, world_view_transform, full_proj_transform)

        return camera

    def _load_gaussian_model(self, cfg_path):
        gaussians = GaussianModel(3) #sh_degree = 3
        gaussians.load_ply(cfg_path)
        return gaussians

    """ Copied and adapted from the Gaussian Splat repo """
    def _get_args(self, cfgfilepath, parser : ArgumentParser):
        cmdlne_string = ""
        cfgfile_string = "Namespace()"
        args_cmdline = parser.parse_args(cmdlne_string)

        try:
            print("Looking for config file in", cfgfilepath)
            with open(cfgfilepath) as cfg_file:
                print("Config file found: {}".format(cfgfilepath))
                cfgfile_string = cfg_file.read()
        except TypeError:
            print("Config file not found at")
            pass
        args_cfgfile = eval(cfgfile_string)

        merged_dict = vars(args_cfgfile).copy()
        for k,v in vars(args_cmdline).items():
            if v != None:
                merged_dict[k] = v
        return Namespace(**merged_dict)

    def _load_pipeline(self, args, args_path):
        pipeline = PipelineParams(args)
        args_load = self._get_args(args_path, args)
        pipeline.extract(args_load)
        return pipeline
    
    def update_camera_pose(self, R, T):
        width = self.camera.image_width
        height = self.camera.image_height
        fovy = self.camera.FoVy
        fovx = self.camera.FoVx
        znear = self.camera.znear
        zfar = self.camera.zfar

        T = torch.Tensor(T).unsqueeze(-1)
        R = torch.Tensor(R)
        A = torch.Tensor([0,0,0,1]).unsqueeze(0)

        # [R|T] is the camera pose relative to world. To transform it to view -> world space, we take the inverse
        # view_mat = torch.concat((torch.concat((torch.t(R), -T), dim=-1), A), dim=0)
        # world_view_transform = torch.reshape(torch.tensor(view_mat), (4, 4)).cuda()
        # world_view_transform[:,1] = -world_view_transform[:,1]
        # world_view_transform[:,2] = -world_view_transform[:,2]
        # full_proj_transform = torch.reshape(torch.tensor(message["view_projection_matrix"]), (4, 4)).cuda()
        # full_proj_transform[:,1] = -full_proj_transform[:,1]
        # world_view_transform = torch.tensor(getWorld2View2(R, T, trans, scale)).transpose(0, 1).cuda()

        world_view_transform = torch.tensor(getWorld2View(R, T)).transpose(0, 1).cuda()
        projection_matrix = getProjectionMatrix(znear=znear, zfar=zfar, fovX=fovx, fovY=fovy).transpose(0,1).cuda()
        full_proj_transform = (world_view_transform.unsqueeze(0).bmm(projection_matrix.unsqueeze(0))).squeeze(0)

        self.camera = MiniCam(width, height, fovy, fovx, znear, zfar, world_view_transform, full_proj_transform)

    def render_gaussians(self):
        with torch.no_grad():
            rendering = gaussian_splatting.gaussian_renderer.render(self.camera, self.gaussians, self.pipeline, torch.Tensor([0,0,0]).cuda())["render"]

        # Save the rendered image
        img = (rendering.detach().permute(1,2,0).cpu().numpy()*255).astype(int)
        cv2.imwrite(self.save_path, img)

        print("saving to "+self.save_path)

        # Return the render
        return img