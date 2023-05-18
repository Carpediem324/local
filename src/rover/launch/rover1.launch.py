# Author: Addison Sears-Collins
# Date: September 1, 2021
# Description: Launch a basic mobile robot
# https://automaticaddison.com

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

  # Set the path to different files and folders.
  pkg_gazebo_ros = FindPackageShare(package='gazebo_ros').find('gazebo_ros')   
  pkg_share = FindPackageShare(package='rover').find('rover')
  default_launch_dir = os.path.join(pkg_share, 'launch')
  world_path = os.path.join(pkg_share, 'worlds/race2.world')
  sdf_model_path = 'models/rover_with_2d_lidar/model.sdf'
  #sdf_model_path = 'models/rover_with_depth_camera/model.sdf'
  sdf_model_path = os.path.join(pkg_share, sdf_model_path)
 
  # Pose where we want to spawn the robot
  spawn_x_val = '0.0'
  spawn_y_val = '0.0'
  spawn_z_val = '0.0'
  spawn_yaw_val = '0.0'

  # Launch configuration variables specific to simulation
  headless = LaunchConfiguration('headless')
  model = LaunchConfiguration('model')
  rviz_config_file = LaunchConfiguration('rviz_config_file')
  use_robot_state_pub = LaunchConfiguration('use_robot_state_pub')
  use_rviz = LaunchConfiguration('use_rviz')
  use_sim_time = LaunchConfiguration('use_sim_time')
  use_simulator = LaunchConfiguration('use_simulator')
  world = LaunchConfiguration('world')
  model_name = LaunchConfiguration('model_name')
  sdf_model = LaunchConfiguration('sdf_model')

  declare_simulator_cmd = DeclareLaunchArgument(
    name='headless',
    default_value='False',
    description='Whether to execute gzclient')
    
  declare_use_sim_time_cmd = DeclareLaunchArgument(
    name='use_sim_time',
    default_value='True',
    description='Use simulation (Gazebo) clock if true')

  declare_use_simulator_cmd = DeclareLaunchArgument(
    name='use_simulator',
    default_value='True',
    description='Whether to start the simulator')

  declare_world_cmd = DeclareLaunchArgument(
    name='world',
    default_value=world_path,
    description='Full path to the world model file to load')

  declare_sdf_model_path_cmd = DeclareLaunchArgument(
    name='sdf_model',
    default_value=sdf_model_path,
    description='Absolute path to robot sdf file')

  declare_model_name_cmd = DeclareLaunchArgument(
    name='model_name',
    default_value='depth_camera',
    description='model name with rover')


  # Specify the actions

  # Start Gazebo server
  start_gazebo_server_cmd = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
        os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')),
    condition=IfCondition(use_simulator),
    launch_arguments={'world': world}.items())

  # Start Gazebo client    
  start_gazebo_client_cmd = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
        os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')),
    condition=IfCondition(PythonExpression([use_simulator, ' and not ', headless])))

  # Start robot localization using an Extended Kalman filter

  # Launch the robot
  spawn_entity_cmd = Node(
    package='gazebo_ros',
    executable='spawn_entity.py',
    arguments=['-entity', 'simple_model',
               '-file', sdf_model,
                  '-x', spawn_x_val,
                  '-y', spawn_y_val,
                  '-z', spawn_z_val,
                  '-Y', spawn_yaw_val],
                  output='screen')

  
  # Create the launch description and populate
  ld = LaunchDescription()

  # Declare the launch options
  ld.add_action(declare_simulator_cmd)
  ld.add_action(declare_use_sim_time_cmd)
  ld.add_action(declare_use_simulator_cmd)
  ld.add_action(declare_world_cmd)
  ld.add_action(declare_sdf_model_path_cmd)
  ld.add_action(declare_model_name_cmd)

  # Add any actions
  ld.add_action(start_gazebo_server_cmd)
  ld.add_action(start_gazebo_client_cmd)
  ld.add_action(spawn_entity_cmd)

  return ld
