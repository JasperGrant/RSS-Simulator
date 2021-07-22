#!/bin/env bash

allmake(){
	catkin_make
	cd ..
	cd gazebo_plugin_tutorial
	cd build
	cmake ../
	make
	cd ..
	cd ..
	cd catkin_ws
}

RSSlaunch(){
	killall -9 roscore
	killall -9 rosmaster
	killall -9 gzclient gzserver
	roscore &
	gazebo RSS_world.world
}

RSSkill(){
	killall -9 gzclient gzserver
	kill -9 $(pgrep bash)
	killall -9 roscore
	killall -9 rosmaster
}
