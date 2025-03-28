"""
A basic ROS2 node that simulates naive navigation, POSTs the position estimates to the 
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import yaml
import os
import requests

class NavigatorNode(Node):
    def __init__(self):
        super().__init__('navigator_client')

        # Declare parameters for configuration (endpoint URL)
        self.declare_parameter('endpoint_url', 'http://127.0.0.1:5000/post_endpoint')  # Default URL

        # Load the Flask endpoint URL from the parameter server
        self.flask_endpoint_url = self.get_parameter('endpoint_url').get_parameter_value().string_value
        self.get_logger().info(f"Flask endpoint URL: {self.flask_endpoint_url}")

        # Create a subscriber to listen to a string topic
        self.subscription = self.create_subscription(
            String,
            'flask_request_topic',
            self.listener_callback,
            10
        )
        
        # Timer to request data from the flask server every second
        self.request_timer = self.create_timer(1.0, self.timer_callback)

        self.get_logger().info("Flask POST Client Node Initialized")

    def listener_callback(self, msg):
        # This method gets called when a message is received on the topic
        self.get_logger().info(f"Received message: {msg.data}")
        self.send_post_request(msg.data)

    def send_post_request(self, data):
        # Prepare data for the POST request (can be customized to your Flask server's expected format)
        payload = {'message': data}

        try:
            # Sending POST request to the Flask server
            response = requests.post(self.flask_endpoint_url, json=payload)

            if response.status_code == 200:
                self.get_logger().info("Successfully sent POST request")
                self.get_logger().info(f"Server response: {response.text}")
            else:
                self.get_logger().error(f"Failed to send POST request, Status Code: {response.status_code}")
        except requests.exceptions.RequestException as e:
            self.get_logger().error(f"Error while making POST request: {e}")

    def timer_callback(self):
        # Optional: Send a test message every 1 second
        test_message = String()
        test_message.data = "Test message to Flask server"
        self.publisher.publish(test_message)

def main(args=None):
    rclpy.init(args=args)

    # Load configuration from a YAML file
    config_file = os.path.join(os.getcwd(), 'your_package', 'config', 'config.yaml')  # Adjust path as needed
    if os.path.exists(config_file):
        with open(config_file, 'r') as file:
            config = yaml.safe_load(file)
            flask_endpoint_url = config.get('flask', {}).get('endpoint_url')
            rclpy.get_default_context().params['na'] = flask_endpoint_url
    else:
        print(f"Warning: Configuration file {config_file} not found, using default endpoint URL.")

    node = NavigatorNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
