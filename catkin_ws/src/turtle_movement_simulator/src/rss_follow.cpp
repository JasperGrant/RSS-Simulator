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
	//std::thread forwardMovementThread(translate, vel_pub, vel_msg);
	//forwardMovementThread.detach();
	ros::Rate rate(0.01);
	int i = 0;
	vel_msg.linear.x = 0;
	vel_msg.angular.z = 0;
	while(ros :: ok()){
		//std::cout << "debris x,y: " << debris_position.position.x << " , " << debris_position.position.y << std::endl;
		//std::cout << "IMU x,y: " << IMU.pose.position.x << " , " << IMU.pose.position.y << std::endl;
		//std::cout << "debris_angle" << debris_angle << std::endl;
		//debris_angle = anglefinder(debris_position.position.x - IMU.pose.position.x,debris_position.position.y - IMU.pose.position.y);
		//rotate(debris_angle, vel_pub, vel_msg);

		deciding_angle = anglefinder(debris_position.position.x - IMU.pose.position.x,debris_position.position.y - IMU.pose.position.y) - IMUangle;
		if(deciding_angle < -PI){
			std::cout << "stuck 2" << std::endl;
			deciding_angle = deciding_angle + 2*PI;
		}
		if(deciding_angle >= PI){
			std::cout << "stuck 2" << std::endl;
			deciding_angle = deciding_angle - 2*PI;
		}
		std :: cout << "IMUangle: " << IMUangle << " deciding angle: " << deciding_angle << " debris angle: " << deciding_angle + IMUangle << std::endl;
		if(deciding_angle > 0 && IMU.velocity.angular.z < 1){
			vel_msg.angular.z = -1;
		}
		else if(deciding_angle < 0 && IMU.velocity.angular.z > -1){
			vel_msg.angular.z = 1;
		}
		else{
			vel_msg.angular.z = 0;
		}
		if(abs(deciding_angle) < 0.32665){
			vel_msg.linear.x = 1;
		}
		else{
			vel_msg.linear.x = 0;
		}
//RSS continues accelerating despite only getting force once at the start

		vel_pub.publish(vel_msg);

	}
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

float anglefinder(float coordX, float coordY){
	float angle;
	if(coordX == 0 && coordY == 0){
		angle = IMUangle;
	}
	else if(coordX == 0){
		if(coordY<0){	
			angle = -PI/2;
		}
		else{
			angle = PI/2;
		}
	}
	else if(coordX < 0){
		angle = atan(coordY/coordX)+PI;
	}
	else{
		angle = atan(coordY/coordX);
	}
	if(angle<0){
		angle+=2*PI;
	}
	return angle;
}

void translate(ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
	while(ros :: ok()){
		if(abs(deciding_angle) < 0.32665){
			vel_msg.linear.x =  1;
		}
		else{
			vel_msg.linear.x = 0;
		}
		vel_pub.publish(vel_msg);
	}	

}

