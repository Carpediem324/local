import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Twist #이동 관련된 파일 임포트
from std_msgs.msg import String

class HelloworldPublisher(Node):

    def __init__(self):
        super().__init__('helloworld_publisher')
        qos_profile = QoSProfile(depth=10)
        self.helloworld_publisher = self.create_publisher(Twist, '/cmd_vel', qos_profile)
        self.timer = self.create_timer(1, self.publish_helloworld_msg)
        self.count = 0

    def publish_helloworld_msg(self):
        move_cmd = Twist()
        move_cmd.linear.x = 0.0
        move_cmd.linear.y = 0.0
        move_cmd.linear.z = 0.0
        move_cmd.angular.x =0.0
        move_cmd.angular.y =0.0
        move_cmd.angular.z =0.0
                                  

        move_cmd.linear.x = -1.0  #직진
        if self.count >18 :              # 정지
            move_cmd.linear.x = 0.0
            move_cmd.linear.y = 0.0
            move_cmd.linear.z = 0.0
            move_cmd.angular.x =0.0
            move_cmd.angular.y =0.0
            move_cmd.angular.z =0.0

        self.helloworld_publisher.publish(move_cmd)  #publish
        self.count +=1

def main(args=None):
    rclpy.init(args=args)
    node = HelloworldPublisher()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ =='__main__':
    main()
