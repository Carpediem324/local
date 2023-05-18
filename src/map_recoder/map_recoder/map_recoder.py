#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from datetime import datetime
from math import *
import shutil
import threading
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
import string
import os, time
from nav_msgs.msg import Odometry
import sys, tty, select, termios

import numpy as np

import random
import matplotlib.pyplot as plt

import getch
import glob
#os.gelogin()

import getpass

user = getpass.getuser()
if user == 'root':
    parent_dir = '/'
else:
    parent_dir = os.path.join('/home', user)

TARGET_SAVE_PATH = os.path.join(parent_dir, 'ws', 'src', 'map_recoder', 'map')


GPS_TOPIC = 'odom'

class MapRecorder(Node):
    def __init__(self):
        super().__init__('map_recorder')
        
        self.save_mode = 0
        self.callback_counter = 0
        self.settings = None
        self.utm = np.empty((0, 2), dtype=np.float32)
        self.total_saved = []
        self.cx, self.cy = [], []
        self.pre_x, self.pre_y = 0, 0

        self.topic_check_time = time.time()

        self.idx = 0
        qos = QoSProfile(depth=10)
        self.sub = self.create_subscription(Odometry, GPS_TOPIC, self.text_callback, qos)

        # count files in specific location
        file_list = [f for f in os.listdir(TARGET_SAVE_PATH) if os.path.isfile(os.path.join(TARGET_SAVE_PATH, f))]

        if len(file_list)!=0:

            #in order to determine the title of backup folder to first item of existing files.
            abs_path = os.path.join(TARGET_SAVE_PATH,file_list[0])
            new_folder_path = os.path.join(TARGET_SAVE_PATH,self.get_file_time(abs_path))
            self.get_logger().warn(f'since there are files in save path, executing backup created to : {new_folder_path}')
            if not os.path.exists(new_folder_path):
                os.mkdir(new_folder_path)

            # breakpoint()
            for f in file_list:
                shutil.move(os.path.join(TARGET_SAVE_PATH, f), os.path.join(new_folder_path,f))

        
        self.get_logger().info("#### #### MAP SAVER #### ####\n")
        self.get_logger().info("writing x,y for UTM")
        self.get_logger().info("Press 'P' to -pause-, 'S' to -Stop program-")


        self.exit_event = threading.Event()
        input_thread = threading.Thread(target=self.get_input, args=(self.exit_event,self.idx,))
        input_thread.daemon = True
        input_thread.start()
        
    def get_file_time(self, filepath):

        tm = os.path.getmtime(filepath)
        dt = datetime.fromtimestamp(tm)

        now = datetime.now()
        return dt.strftime("bak_%y%m%d_%H%M%S")

    def get_input(self, exit_event,idx):
        # Set stdin to non-blocking mode
        self.settings = termios.tcgetattr(sys.stdin)

        tty.setcbreak(sys.stdin.fileno())

        while True:
            # Check if there is any input waiting on stdin
            if select.select([sys.stdin], [], [], 0)[0]:
                # Read a single character of input from stdin
                user_input = getch.getch()

                # Do something with the user input (e.g. print it)
                # print("You entered:", user_input)
                if user_input == 'p' or user_input == 'P':
                    if len(self.utm)!=0:
                        self.idx = self.idx+1
                        self.total_saved.append(self.utm)
                        self.utm = np.empty((0, 2),dtype=np.float32)
                    else:
                        print('\n')
                        self.get_logger().error('recording less than 1 sample is prohibited.')
                    # another modes are here

                elif user_input == 's' or user_input == 'S':
                    # os._exit()
                    if len(self.total_saved) == 0:
                        self.total_saved.append(self.utm)

                    exit_event.set()
                    break

            if time.time() - self.topic_check_time > 3:
                if self.callback_counter == 0:
                    self.get_logger().warn(f'i think The topic \'{GPS_TOPIC}\' I\'m subscribing is not that publishing anything. please check the topic again.')
                    self.topic_check_time = time.time()
        return


    def text_callback(self, msg):
        self.callback_counter = self.callback_counter+1
        target_utm = np.array([msg.pose.pose.position.x,msg.pose.pose.position.y])

        print(f'\r recording : {self.idx +1}.txt |  {target_utm}', end='')
        self.utm = np.append(self.utm, [target_utm], axis=0)

    def save_to_txt(self):
        for i, l in enumerate(self.total_saved):
            # self.get_logger().error(l)
            np.savetxt(os.path.join(TARGET_SAVE_PATH,f'{i+1}.txt'), l, delimiter=',', fmt='%.8f')
        self.get_logger().info('save done.')

    def plot(self, save_fig = True):            
        for i, u in enumerate(self.total_saved):
            random.seed(time.time())
            r = random.random()
            g = random.random()
            b = random.random()
            random_rgb=(r,g,b)

            x_start = u[0,0]
            x_end = u[-1,0]
            y_start = u[0,1]
            y_end = u[-1,1]

            plt.plot(u[:,0], u[:,1], c=random_rgb, marker= '.' ,markersize=6)
            #start point
            if i == 0:
                plt.text(x_start, y_start, "Start", fontsize=13, color='r')

            #end point
            elif i == len(self.total_saved)-1:
                plt.text(x_end, y_end, "End", fontsize=13, color='r')

            plt.text(np.mean(u[:,0]),np.mean(u[:,1]), "{}.txt".format(str(i+1)), fontsize=13)

        tm = time.localtime(time.time())
        string = time.strftime('%Y_%m_%d_ %I_%M_%S_%p', tm)
        plt.title(string)
        plt.xlabel('x')
        plt.ylabel('y')
        plt.axis("equal")
        plt.grid(True)

        plt.savefig(os.path.join(TARGET_SAVE_PATH,f'{string}.png'),dpi=300)
        plt.show()

def main(args=None):
    rclpy.init(args=args)

    mr = MapRecorder()

    while rclpy.ok():
        rclpy.spin_once(mr)

        mr.exit_event.wait()
        print('')
        mr.get_logger().warn(f'Stopped Recording gps path at {mr.idx+1}.txt')
        mr.save_to_txt()
        mr.plot(save_fig=True)

        mr.destroy_node()
        break
    
    #restore terminal
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, mr.settings)

    plt.close('all')
    sys.exit(0)

if __name__ == '__main__':
    main()

