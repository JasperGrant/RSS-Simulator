#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <thread>
#include "turtle_movement_simulator/imu.h"
#define PI 3.141592654

turtle_movement_simulator::imu IMU;

geometry_msgs::Pose debris_position;

float IMUangle, deciding_angle;

float anglefinder(float coordX, float coordY);

void imuRead(void);

void imudRead(void);

void imuCallback(turtle_movement_simulator::imu imumsg);

void imudCallback(geometry_msgs::Pose pos);

void translate(ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

void rotate(float end, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

int main(int argc, char** argv)
{
	std::thread imuSubThread(imuRead);
	imuSubThread.detach();
	std::thread imudSubThread(imudRead);
	imudSubThread.detach();
	ros::init(argc, argv, "movement_node");
	ros::NodeHandle nh;
	ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
	geometry_msgs::Twist vel_msg;
	ros::Rate rate(0.0001);
	ros::Time time_begin = ros::Time::now();
	ros::Duration duration(5);
	while(ros::Time::now() - time_begin < duration){
		vel_msg.linear.x = 1;
		vel_pub.publish(vel_msg);
	}
	std::cout << "Velocity: " << IMU.velocity.linear.x << std::endl;
}


void imuCallback(turtle_movement_simulator::imu imumsg){
	IMU = imumsg;
	float placeholder =  atan2(2.0f * (IMU.pose.orientation.w * IMU.pose.orientation.z + IMU.pose.orientation.x * IMU.pose.orientation.y), IMU.pose.orientation.w * IMU.pose.orientation.w + IMU.pose.orientation.x * IMU.pose.orientation.x - IMU.pose.orientation.y * IMU.pose.orientation.y - IMU.pose.orientation.z * IMU.pose.orientation.z)+PI/2;
	while(placeholder<0){
		 placeholder += 2*PI;
	}
	IMUangle = placeholder;

}

void imudCallback(geometry_msgs::Pose pos){
	debris_position = pos;
}

void imuRead(void){
	int argc = 0;
	char** argv = NULL;
	ros::init(argc, argv, "imu_subscriber_node");
	ros::NodeHandle ns;
	ros::Subscriber imusub = ns.subscribe("imu", 1000, &imuCallback);
	ros::MultiThreadedSpinner imuspinner(1);
	imuspinner.spin();
}

void imudRead(void){
	int argc = 0;
	char** argv = NULL;
	ros::init(argc, argv, "imud_subscriber_node");
	ros::NodeHandle nsd;
	ros::Subscriber imudsub = nsd.subscribe("debris_pose", 1000, &imudCallback);
	ros::MultiThreadedSpinner imudspinner(1);
	imudspinner.spin();
}

