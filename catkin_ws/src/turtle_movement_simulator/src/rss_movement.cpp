#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <thread>
#include "turtle_movement_simulator/imu.h"
#include <geometry_msgs/Pose.h>
#define PI 3.141592654

turtle_movement_simulator::imu IMU;

float IMUangle;

float anglefinder(float coordX, float coordY);

void translate(float coordX, float coordY, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

void rotate(float end, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

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
	bool trials;
	int i = 0;
	while(ros :: ok()){
		std::cout << "Enter 1 for trials matrix or 0 for coordinate enter mode: " << std::endl;
		std::cin >> trials;
		if(trials == 1){
			rotate(anglefinder(5 - IMU.pose.position.x,5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(5 - IMU.pose.position.x, 5 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(-5 - IMU.pose.position.x,-5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(-5 - IMU.pose.position.x, -5 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(5 - IMU.pose.position.x,-5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(5 - IMU.pose.position.x, -5 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(-5 - IMU.pose.position.x,5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(-5 - IMU.pose.position.x, 5 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(0 - IMU.pose.position.x,0 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(0 - IMU.pose.position.x, 0 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(5 - IMU.pose.position.x,0 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(5 - IMU.pose.position.x, 0 - IMU.pose.position.y, vel_pub, vel_msg);
	
			rotate(anglefinder(-5 - IMU.pose.position.x,0 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(-5 - IMU.pose.position.x, 0 - IMU.pose.position.y, vel_pub, vel_msg);


			rotate(anglefinder(0 - IMU.pose.position.x,5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(0 - IMU.pose.position.x, 5 - IMU.pose.position.y, vel_pub, vel_msg);

			rotate(anglefinder(0 - IMU.pose.position.x,-5 - IMU.pose.position.y), vel_pub, vel_msg);
			translate(0 - IMU.pose.position.x, -5 - IMU.pose.position.y, vel_pub, vel_msg);

			vel_msg.linear.y = 1;
			while(i<500){
				vel_pub.publish(vel_msg);
				i++;
			}
			vel_msg.linear.y = -1;
			while(i<500){
				vel_pub.publish(vel_msg);
				i++;
			}
			std::cout << "Finished" << std::endl;
		}

		if(trials == 0){
			float newcoordX = 0, newcoordY = 0;
			float coords[10][2];
			while(newcoordX!=99 || newcoordY!=99){
				std::cout << "Enter coordinate to add to list in format X Y:"
	 << std::endl << "99 99 to quit" << std::endl;
				std::cin >> newcoordX >> newcoordY;
				coords[i][0] = newcoordX;
				coords[i][1] = newcoordY;
				i+=1;
			}
			float distance, angle;
			int j = 0;
			while(j<i-1){
				angle = anglefinder(coords[j][0] - IMU.pose.position.x,coords[j][1] - IMU.pose.position.y);
				rotate(angle, vel_pub, vel_msg);
				translate(coords[j][0] - IMU.pose.position.x, coords[j][1] - IMU.pose.position.y, vel_pub, vel_msg);
				j+=1;
			}
			rotate(2*PI, vel_pub, vel_msg);
			
		}
		else{
			std::cout << "Unrecognized input" << std::endl;
		}
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

void imuRead(void){
	int argc = 0;
	char** argv = NULL;
	ros::init(argc, argv, "imu_subscriber_node");
	ros::NodeHandle ns;
	ros::Subscriber imusub = ns.subscribe("imu", 1000, &imuCallback);
	ros::spin();
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

void translate(float coordX, float coordY, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
		vel_msg.linear.x = 1;
		float mass = 13.0, force = 5.0;
	while(sqrt((coordX - IMU.pose.position.x)*(coordX - IMU.pose.position.x) + (coordY - IMU.pose.position.y)*(coordY - IMU.pose.position.y)) > 0.01){
		if(sqrt((coordX - IMU.pose.position.x)*(coordX - IMU.pose.position.x) + (coordY - IMU.pose.position.y)*(coordY - IMU.pose.position.y)) < (IMU.velocity.linear.x * IMU.velocity.linear.x * mass)/(2 * force)){
			vel_msg.linear.x = -1;
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
}

void rotate(float end, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
	std::cout << "current angle: " << IMUangle << " target angle: " << end << std::endl;
	if(end > 2*PI){
		end-=2*PI;
	}
	if(end-IMUangle < PI && end > IMUangle){
		std::cout <<"1: "<< IMUangle << std::endl;
		while(IMUangle < end){
			vel_msg.angular.z = 1;
			vel_pub.publish(vel_msg);
			std::cout <<"1: "<< IMUangle <<"end: "<< end << std::endl;
		}
	}
	else if(IMUangle-end < PI && IMUangle > end){
		std::cout <<"2: "<< IMUangle << std::endl;
		while(IMUangle > end && IMUangle < 6){
			vel_msg.angular.z = -1;
			vel_pub.publish(vel_msg);
			std::cout <<"2: "<< IMUangle << std::endl;
		}

	}	
	else if(IMUangle > end){
		std::cout <<"3: "<< IMUangle << std::endl;
		while(IMUangle >= 6){
			vel_msg.angular.z = 1;
			vel_pub.publish(vel_msg);
		}
		while(IMUangle < end){
			vel_msg.angular.z = 1;
			vel_pub.publish(vel_msg);
			std::cout <<"3: "<< IMUangle << std::endl;
		}
	}
	else if(end > IMUangle){
		std::cout << "4: "<< IMUangle << std::endl;
		while(IMUangle <= 6){
			vel_msg.angular.z = -1;
			vel_pub.publish(vel_msg);
		}
		while(IMUangle > end){
			vel_msg.angular.z = -1;
			vel_pub.publish(vel_msg);
			std::cout << "4: "<< IMUangle << std::endl;
		}

	}
	
	vel_msg.angular.z = 0;
	vel_pub.publish(vel_msg);
	ROS_INFO("FOUND ANGLE");
}

