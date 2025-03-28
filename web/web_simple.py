"""
A simple Flask server that accepts position and orientation requests and stores them,
simulating a naive web trajectory request server
"""

from flask import Flask, request, render_template, jsonify, Response, send_file
import numpy as np
from .constructs import Position, Orientation
import os
import cv2

app = Flask(__name__, template_folder='')

# Path of file to which we render to (for HTML display)
folder_path = os.path.abspath("static/images")
image_path = os.path.join(folder_path,"image.jpeg" )
# The actual rendered file
image = cv2.imread(image_path)

# Store the coordinates (for retrieval) and image name
position = Position()
orientation = Orientation()

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

    return render_template('index.html', x=position.x, y=position.y, z=position.z, yaw=orientation.yaw,\
                           pitch=orientation.pitch, roll=orientation.roll)

@app.route('/get-coords', methods=['GET'])
def get_data():
    global position
    return jsonify({"x": position.x, "y": position.y, "z": position.z}), 200

if __name__ == '__main__':
    # Render inital gaussian to the image based on image coordinates
    app.run(debug=True, host="0.0.0.0")
