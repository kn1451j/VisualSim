from gaussian_renderer import render
from scene.gaussian_model import GaussianModel
import torch
import cv2

def render_save_gaussian(cam_position, cam_orientation, image_save_path):
    # TODO Render to the image based on image coordinates
    with torch.no_grad():
        gaussians = GaussianModel(dataset.sh_degree)
        scene = Scene(dataset, gaussians, load_iteration=iteration, shuffle=False)
        MiniCam()
    rendering = render(view, gaussians, pipeline, background, use_trained_exp=train_test_exp, separate_sh=separate_sh)["render"]

    # Save the rendered image
    cv2.imwrite(image_save_path, rendering)

    # Return the render
    return rendering