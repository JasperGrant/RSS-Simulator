#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <thread>
#include "turtle_movement_simulator/imu.h"
#include <geometry_msgs/Pose.h>
#define PI 3.141592654

turtle_movement_simulator::imu IMU;

void translate(float coordX, float coordY, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

void imuRead(void);

void imuCallback(turtle_movement_simulator::imu imumsg);

int main(int argc, char** argv)
{	
	std::thread imuSubThread(imuRead);
	imuSubThread.detach();
	ros::init(argc, argv, "movement_node");
	ros::NodeHandle nh;
	ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
	geometry_msgs::Twist vel_msg;
	ros::Rate rate(0.5);
	while(ros :: ok()){
		translate(0,4, vel_pub, vel_msg);
		translate(4,4, vel_pub, vel_msg);
		translate(4,0, vel_pub, vel_msg);
		translate(0,0, vel_pub, vel_msg);
	}
}

void imuCallback(turtle_movement_simulator::imu imumsg){
	IMU = imumsg;
}

void imuRead(void){
	int argc = 0;
	char** argv = NULL;
	ros::init(argc, argv, "imu_subscriber_node");
	ros::NodeHandle ns;
	ros::Subscriber imusub = ns.subscribe("imu", 1000, &imuCallback);
	ros::spin();
}


void translate(float coordX, float coordY, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
	float mass = 4.5, force = 0.3;
	while(coordX - IMU.pose.position.x > 0){
		std::cout << "Step 1" <<std::endl;
		vel_msg.linear.x = 1;
		if(IMU.velocity.linear.x < -0.01){
			vel_msg.linear.x = 0;
			vel_pub.publish(vel_msg);
			break;
		}
		else if(coordX - IMU.pose.position.x < (IMU.velocity.linear.x * IMU.velocity.linear.x * mass)/(2 * force)){
			vel_msg.linear.x = -1;			
		}
		else{
			vel_msg.linear.x = 1;
		}
		vel_pub.publish(vel_msg);
	}
	while(coordX - IMU.pose.position.x < 0){
		std::cout << "Step 2" <<std::endl;
		if(IMU.velocity.linear.x > 0.01){
			vel_msg.linear.x = 0;
			vel_pub.publish(vel_msg);
			break;
		}
		else if(coordX - IMU.pose.position.x > (IMU.velocity.linear.x * IMU.velocity.linear.x * mass)/(2 * force)){
			vel_msg.linear.x = 1;			
		}
		else{
			vel_msg.linear.x = -1;
		}
		vel_pub.publish(vel_msg);
	}
	while(coordY - IMU.pose.position.y > 0){
		std::cout << "Step 3" <<std::endl;
		if(IMU.velocity.linear.y < -0.01){
			vel_msg.linear.y = 0;
			vel_pub.publish(vel_msg);
			break;
		}
		else if(coordY - IMU.pose.position.y < (IMU.velocity.linear.y * IMU.velocity.linear.y * mass)/(2 * force)){
			vel_msg.linear.y = -1;			
		}
		else{
			vel_msg.linear.y = 1;
		}
		vel_pub.publish(vel_msg);
	}
	while(coordY - IMU.pose.position.y < 0){
		std::cout << "Step 4" <<std::endl;
		if(IMU.velocity.linear.y > 0.01){
			vel_msg.linear.y = 0;
			vel_pub.publish(vel_msg);
			break;
		}
		if(coordY - IMU.pose.position.y > (IMU.velocity.linear.y * IMU.velocity.linear.y * mass)/(2 * force)){
			vel_msg.linear.y = 1;			
		}
		else{
			vel_msg.linear.y = -1;
		}
		vel_pub.publish(vel_msg);
	}



/*
	while(abs(coordX - IMU.pose.position.x){
		if(abs(coordX - IMU.pose.position.x) < (IMU.velocity.linear.x * IMU.velocity.linear.x * mass)/(2 * force)){
			vel_msg.linear.x *= -1;
			}
		}
	while(abs(coordY - IMU.pose.position.y	)){
		if(abs(coordY - IMU.pose.position.x) < (IMU.velocity.linear.y * IMU.velocity.linear.y * mass)/(2 * force)){
			vel_msg.linear.y *= -1;
			}
		}
		if(IMU.velocity.linear.x < -0.01){
			vel_msg.linear.x = 0;
		}
		vel_pub.publish(vel_msg);
		std::cout << "X: " << IMU.pose.position.x << "Y: " << IMU.pose.position.y << std::endl;
	}
	ROS_INFO("FOUND DISTANCE");
	vel_msg.linear.x = 0;
	vel_pub.publish(vel_msg);
*/
}


