from flask import Flask, request, render_template, jsonify, Response
from render_img import render_save_gaussian
import numpy as np

app = Flask(__name__)

# Path of file to which we render to (for HTML display)
image_path = "image.jpeg" 
# The actual rendered file
image = np.array([])

# Store the coordinates (for retrieval) and image name
position = np.zeros(3)
orientation = np.eye(3,3)
coordinate_bounds = [-1, 1]

# Main page route with the form and image
@app.route('/', methods=[])
def home():
    return render_template('index.html', x=x, y=y, z=z, image_name=image_path)

# POST route to accept JSON data
@app.route('/send-coords', methods=['POST'])
def post_data():
    if request.is_json:
        data = request.get_json()
        stored_coordinates['x'] = data.get('position.x')
        stored_coordinates['y'] = data.get('position.y')
        stored_coordinates['z'] = data.get('position.z')
        return jsonify({"message": "Data received successfully!"}), 200
    else:
        return jsonify({"error": "Request must be JSON"}), 400

# GET route to retrieve an image
@app.route('/get-img', methods=['GET'])
def get_image():
    # Return the image as a response with the appropriate content-type
    return Response(image, content_type='image/jpeg')

# GET route to retrieve the stored coordinates
@app.route('/get-coords', methods=['GET'])
def get_data():
    if stored_coordinates:
        return jsonify(stored_coordinates), 200
    else:
        return jsonify({"message": "No data found"}), 404

if __name__ == '__main__':
    # Generate random coordinates within coordinate bounds
    rand_pos = (np.random.rand(3) - 0.5) * 2
    
    # Store the coordinates for retrieval
    stored_coordinates['x'] = rand_pos[0]
    stored_coordinates['y'] = rand_pos[1]
    stored_coordinates['z'] = rand_pos[2]
    
    # TODO Render to the image based on image coordinates
    # Save the rendered image
    cv2.imwrite(image_path, image)

    app.run(debug=True)
