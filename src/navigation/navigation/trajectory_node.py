import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from interfaces.action import Location
from queue import Queue

"""
A tiny trajectory simulation node that serves a Trajectory client (the Navigation node)
and adds requested locations to a queue buffer
"""
class TrajectoryNode(Node):

    def __init__(self):
        super().__init__('navigator_service')
        self.srv = ActionServer(
            self,
            Location,
            'location_found',
            self.log_point
        )

        self.pose_buffer = Queue()
        self.max_length = 20
        self.cur_length = 0
        # to check that we don't fill the buffer with the same points
        self.prev_point = None

    def _same_as_prev(self,point):
        if(self.prev_point is not None and self.prev_point.x == point.x
           and self.prev_point.y == point.y and self.prev_point.z == point.z):
            return True
        self.prev_point = point
        return False

    def log_point(self, handle):
        point = handle.request.pose
        handle.succeed()
        result = Location.Result()
        result.recieved = True

        # if the point is the same as our previous point, don't add it
        if(self._same_as_prev(point)):
            return result

        self.get_logger().info(f"Adding {point} to trajectory")

        # if the pose buffer is full, kick out a pose before adding
        self.cur_length+=1

        if(self.cur_length>self.max_length):
            self.cur_length-=1
            self.pose_buffer.get()

        self.pose_buffer.put(point)
        
        return result

    def carry_out_trajectory(self):
        pass

def main(args=None):
    rclpy.init(args=args)

    minimal_service = TrajectoryNode()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()