"""
A basic ROS2 node that simulates naive navigation, POSTs the position estimates to the 
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from interfaces.action import Detection
import yaml
import os
import requests

class NavigatorNode(Node):
    def __init__(self):
        super().__init__('navigator_client')

        # Declare parameters for configuration (endpoint URL)
        self.declare_parameter('endpoint_url', 'http://127.0.0.1:5000/')  # Default URL

        # Load the Flask endpoint URL from the parameter server
        self.url = self.get_parameter('endpoint_url').get_parameter_value().string_value
        self.get_logger().info(f"Flask endpoint URL: {self.url}")

        # Create a subscriber to listen to a string topic
        self.action_client = ActionClient(
            self,
            Detection,
            'map_detection'
        )
        
        # Timer to request data from the flask server every second
        self.request_timer = self.create_timer(1.0, self.send_get_request)

        self.get_logger().info("Flask POST Client Node Initialized")

    def send_get_request(self):
        try:
            response = requests.get(self.url)
            if response.status_code == 200:
                # Now we send the response to the client
                print(response)
                goal_msg = Detection.Goal()
                goal_msg.img = response.image

                self.action_client.wait_for_server()

                return self.action_client.send_goal_async(goal_msg)
            else:
                self.get_logger().error(f"Error: Received status code {response.status_code}")
        except requests.exceptions.RequestException as e:
            self.get_logger().error(f"Request failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = NavigatorNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
