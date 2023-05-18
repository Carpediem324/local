import time
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Twist #이동 관련된 파일 임포트
from std_msgs.msg import String
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import LaserScan


class HelloworldPublisher(Node):

    def __init__(self):
        super().__init__('helloworld_publisher')
        qos_profile = QoSProfile(depth=10)
        self.helloworld_publisher = self.create_publisher(Twist, '/cmd_vel', qos_profile)
        self.timer = self.create_timer(0.05, self.publish_helloworld_msg)
        self.count = 0
        self.scan_sub = self.create_subscription(LaserScan,'scan',self.scan_callback,qos_profile_sensor_data)  # allows packet loss
        self.frontD=100
        self.leftD =100
        self.rightD =100
        self.RRD = 100
        self.LLD =100
        self.BBD =100
        self.count = 10
    def publish_helloworld_msg(self):
        move_cmd = Twist()
        move_cmd.linear.x = 0.0
        move_cmd.linear.y = 0.0
        move_cmd.linear.z = 0.0
        move_cmd.angular.x =0.0
        move_cmd.angular.y =0.0
        move_cmd.angular.z =0.0
                                  

        if self.frontD < 1.3:
            move_cmd.linear.x=0.0
            move_cmd.linear.y=0.0
            move_cmd.linear.z=0.0
            if self.leftD < 1.7:
                if self.rightD > 1.5:
                    move_cmd.angular.z = 0.7 #turn right
                else :
                    move_cmd.linear.x = 1.0 #back
                    if self.RRD >3:
                        move_cmd.angular.z =   0.5
                    elif self.LLD >3:
                        move_cmd.angular.z = - 0.5
            else :
                move_cmd.angular.z = -0.7#turn left
        else :
            move_cmd.angular.z= 0.0
            move_cmd.linear.x = -1.0
       
        self.helloworld_publisher.publish(move_cmd)  #publish
    def scan_callback(self, msg):
        self.frontD = msg.ranges[0]
        self.leftD = msg.ranges[80]
        self.rightD =msg.ranges[280]
        print('-------------------------------')
        print('Front Distance : ', self.frontD)
        print('Left Distance  : ', self.leftD)
        print('Right Distance : ', self.rightD)
        print('-------------------------------')
        self.RRD = msg.ranges[270]
        self.LLD = msg.ranges[90]
        self.BBD = msg.ranges[180]
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
