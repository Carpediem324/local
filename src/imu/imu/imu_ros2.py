#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import serial
import time
from sensor_msgs.msg import Imu
from std_msgs.msg import Header

port = '/dev/serial/by-id/usb-Silicon_Labs_CP2102N_USB_to_UART_Bridge_Controller_0001-if00-port0'
baud = 921600
gravity = 9.80665

class ImuPublisher(Node):
    def __init__(self):
        super().__init__('imu_pub')
        self.imu_pub = self.create_publisher(Imu, 'imu', 10)
        self.timer = self.create_timer(0.01, self.publish_imu_data)

    def publish_imu_data(self):
        try:
            with serial.Serial(port, baud) as ser:
                data = ser.readline().decode().strip().split(',')
                imu_msg = Imu()
                imu_msg.header = Header()
                imu_msg.header.frame_id = 'imu_link'
                imu_msg.orientation.x = float(data[1])
                imu_msg.orientation.y = float(data[2])
                imu_msg.orientation.z = float(data[3])
                imu_msg.orientation.w = float(data[4])
                imu_msg.angular_velocity.x = float(data[5])
                imu_msg.angular_velocity.y = float(data[6])
                imu_msg.angular_velocity.z = float(data[7])
                imu_msg.linear_acceleration.x = float(data[8]) * gravity
                imu_msg.linear_acceleration.y = float(data[9]) * gravity
                imu_msg.linear_acceleration.z = float(data[10]) * gravity
                self.imu_pub.publish(imu_msg)

        except serial.SerialException:
            self.get_logger().warning(f'Failed to connect to port: {port}, baud rate: {baud}')
            self.timer.cancel()
            self.destroy_node()

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = ImuPublisher()
    rclpy.spin(imu_publisher)
    imu_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

