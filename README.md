This is a simple ROS-Python REST application to simulate a generated image stream for a robotics camera sensor application.

It uses the Gaussian Splat directory to render a pretrained splat based on user camera position posts, and allows communication with two ROS2 nodes for "executing" navigation to the user-requested points.

To use Gaussian Splatting (requires GPU), use web_server.py server. Otherwise, run web_simple.py (which will just display a static image).

# Setup:
### Gaussian Splatting (used for rendering the image scene)

Download a pretrained model from - https://repo-sam.inria.fr/fungraph/3d-gaussian-splatting/datasets/pretrained/models.zip

You will need to configure the paths in render_img.py based on this