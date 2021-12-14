# acore_ros_gui 


ROS package which contains initial GUI for aerialCore project. 

## Run simulation first: 

In order to expore GUI functionality, run simulation first: 
```
roslaunch schunk_lwa4p_gazebo lwa4p_powerline_gazebo_moveit.launch
```

## Run GUI:

Make sure to build ROS workspace and source it properly, after that, 
run following command: 
```
rosrun acore_ros_gui acore_gui_ros_ctl
```

## Environment: 

You can use following [docker](https://github.com/larics/docker_files/tree/master/ros-melodic/moveit_schunk_ros) to create environment which contains everything for 
further GUI development (simulation + qt components). 

# TODO: 

- [ ] Check why execution of 5th joint fails 
- [ ] Add signal handling 
- [ ] Test it extensively 
