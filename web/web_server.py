from flask import Flask, request, render_template, jsonify, Response, send_from_directory
from .render_img import Render
import numpy as np
from src.constructs import Position, Orientation
import os

app = Flask(__name__, template_folder='')

# Path of file to which we render to (for HTML display)
image_path = os.path.abspath("web/static/images/image.jpeg" )
# The actual rendered file
image = np.array([])

# Store the coordinates (for retrieval) and image name
position = Position()
orientation = Orientation()

render = Render("/home/ubuntu/GaussianViewTest/model", image_path)

# Main page route with the form and image
@app.route('/', methods=['GET', 'POST'])
def home():
    global position, orientation, render, image
    if request.method == 'POST':
        position.x = float(request.form.get('x', 0))
        position.y = float(request.form.get('y', 0))
        position.z = float(request.form.get('z', 0))
        orientation.yaw = float(request.form.get('yaw', 0))
        orientation.pitch = float(request.form.get('pitch', 0))
        orientation.roll = float(request.form.get('roll', 0))

        render.update_camera_pose(orientation.to_mat(), position.to_array())
        image = render.render_gaussians()

    return render_template('index.html', x=position.x, y=position.y, z=position.z, yaw=orientation.yaw,\
                           pitch=orientation.pitch, roll=orientation.roll)

# GET route to retrieve an image
@app.route('/get-img', methods=['GET'])
def get_image():
    # Return the image as a response with the appropriate content-type
    return Response(image, content_type='image/jpeg')

# GET route to retrieve the stored coordinates
@app.route('/get-coords', methods=['GET'])
def get_data():
    return jsonify(position.to_array(), orientation.to_array()), 200

if __name__ == '__main__':
    # Render inital gaussian to the image based on image coordinates
    app.run(debug=True, port=2222)