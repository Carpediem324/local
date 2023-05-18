#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Path
from math import sin, cos, pi
from squaternion import Quaternion

class PathPublisher(Node):

    def __init__(self):
        super().__init__('path_msg_TEST')
        self.publisher_ = self.create_publisher(Path, '/path', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.radius = 0.5
        self.increment = 0.5

    def timer_callback(self):
        msg = Path()
        msg.header.frame_id = "world"

        for k in range(19):
            pose = PoseStamped()
            pose.pose.position.x = self.radius * cos(k * 5 * (pi/180))
            pose.pose.position.y = self.radius * sin(k * 5 * (pi/180)) - self.radius
            pose.pose.position.z = 0.0

            quat = Quaternion.from_euler(0.0, 0.0, k*5, degrees=True)

            pose.pose.orientation.x = quat[1]
            pose.pose.orientation.y = quat[2]
            pose.pose.orientation.z = quat[3]
            pose.pose.orientation.w = quat[0]

            msg.poses.append(pose)
        
        self.radius += 0.5
        if self.radius == 5:
            self.radius = 0.5            

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing Path')


def main(args=None):
    rclpy.init(args=args)

    viz_publisher = PathPublisher()

    rclpy.spin(viz_publisher)

    viz_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
