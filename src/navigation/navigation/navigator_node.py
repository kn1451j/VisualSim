"""
A basic ROS2 node that requests positions from a Flask server, communicates with the
"Trajectory" node to add points to a trajectory buffer.
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from rclpy.action import ActionClient
from interfaces.action import Location
import requests

class NavigatorNode(Node):
    def __init__(self):
        super().__init__('navigator_client')

        # Declare parameters for configuration (endpoint URL)
        self.declare_parameter('endpoint_url', 'http://192.168.1.153:2351/get-coords')  # Default URL

        # Load the Flask endpoint URL from the parameter server
        self.url = self.get_parameter('endpoint_url').get_parameter_value().string_value
        self.get_logger().info(f"Flask endpoint URL: {self.url}")

        # Create a subscriber to listen to a string topic
        self.action_client = ActionClient(
            self,
            Location,
            'location_found'
        )
        
        # Timer to request data from the flask server every second
        self.request_timer = self.create_timer(1.0, self.send_get_request)

        self.get_logger().info("Flask POST Client Node Initialized")

    def send_get_request(self):
        try:
            response = requests.get(self.url)
            if response.status_code == 200:
                # Now we send the response to the client
                pose = response.json()
                goal_msg = Location.Goal()

                # Prepare our message
                goal_msg.pose = Point()
                goal_msg.pose.x = float(pose['x'])
                goal_msg.pose.y = float(pose['y'])
                goal_msg.pose.z = float(pose['z'])

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
