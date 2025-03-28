import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from interfaces.action import Detection

class MapperNode(Node):

    def __init__(self):
        super().__init__('navigator_service')
        self.srv = ActionServer(
            self,
            Detection,
            'map_detection',
            self.map_detect
        )
        self.image = []

    def map_detect(self, handle):
        self.image = handle.request.img

        self.get_logger().info("Recieved an image: ")
        self.get_logger().info(self.image)

        handle.succeed()
        result = Detection.Result()
        result.recieved = True
        
        return result


def main(args=None):
    rclpy.init(args=args)

    minimal_service = MapperNode()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()