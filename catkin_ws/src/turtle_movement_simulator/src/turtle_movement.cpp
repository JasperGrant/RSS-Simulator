#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#define PI 3.141592654

float distancefinder(float coordX, float coordY);

float anglefinder(float coordX, float coordY, float current_angle);

void translate(float distance, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

void rotate(float start, float end, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg);

int main(int argc, char** argv)
{
	ros::init(argc, argv, "movement_node");
	ros::NodeHandle nh;
	ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
	geometry_msgs::Twist vel_msg;
	ros::Rate rate(0.5);
	float oldcoordX = 0, oldcoordY = 0;
	while(ros :: ok()){
		int i = 0;
		float newcoordX = 0, newcoordY = 0;
		float relativecoords[10][2];
		while(newcoordX!=99 || newcoordY!=99){
			std::cout << "Enter coordinate to add to list in format X Y:"
 << std::endl << "99 99 to quit" << std::endl;
			std::cin >> newcoordX >> newcoordY;
			relativecoords[i][0] = newcoordX - oldcoordX;
			relativecoords[i][1] = newcoordY - oldcoordY;
			if(newcoordX!=99 || newcoordY!=99){
				oldcoordX = newcoordX;
				oldcoordY = newcoordY;
			}
			i+=1;
		}
		float current_angle = 0, distance, angle;
		int j = 0;
		while(j<i-1){
			distance = distancefinder(relativecoords[j][0],relativecoords[j][1]);
			angle = anglefinder(relativecoords[j][0],relativecoords[j][1], current_angle);
			rotate(current_angle, angle, vel_pub, vel_msg);
			current_angle = angle;
			translate(distance, vel_pub, vel_msg);
			j+=1;
		}
		rotate(current_angle, 2.0*PI, vel_pub, vel_msg);
		


	}
}

float distancefinder(float coordX, float coordY){
	return abs(sqrt(pow(coordX,2)+pow(coordY,2)));
}

float anglefinder(float coordX, float coordY, float current_angle){
	float angle;
	if(coordX == 0 && coordY == 0){
		angle = current_angle;
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

void translate(float distance, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
	vel_msg.linear.x = 1;
	double t0 = ros::Time::now().toSec(), t1;
	float current_distance = 0;
	while(current_distance < distance){
		vel_pub.publish(vel_msg);
		t1 = ros::Time::now().toSec();
		current_distance = vel_msg.linear.x*(t1-t0);
	}
	vel_msg.linear.x = 0;
	vel_pub.publish(vel_msg);
}

void rotate(float start, float end, ros::Publisher vel_pub, geometry_msgs::Twist vel_msg){
	double t0 = ros::Time::now().toSec(), t1;
	float current_angle;
	if(start > 2*PI){
		start-=2*PI;
	}
	if(end > 2*PI){
		end-=2*PI;
	}
	if(end-start < PI && end > start){
		vel_msg.angular.z = 1;
		current_angle = start;
		while(current_angle < end){
			vel_pub.publish(vel_msg);
			t1 = ros::Time::now().toSec();
			current_angle = start + vel_msg.angular.z*(t1-t0);
		}	
	}
	else if(start-end < PI && start > end){
		vel_msg.angular.z = -1;
		current_angle = start;
		while(current_angle > end){
			vel_pub.publish(vel_msg);
			t1 = ros::Time::now().toSec();
			current_angle = start + vel_msg.angular.z*(t1-t0);
		}
	}	
	else if(start > end){
		end+=2*PI;
		vel_msg.angular.z = 1;
		current_angle = start;
		while(current_angle < end){
			vel_pub.publish(vel_msg);
			t1 = ros::Time::now().toSec();
			current_angle = start + vel_msg.angular.z*(t1-t0);
		}		
	}
	else if(end > start){
		start+=2*PI;
		vel_msg.angular.z = -1;
		current_angle = start;
		while(current_angle > end){
			vel_pub.publish(vel_msg);
			t1 = ros::Time::now().toSec();
			current_angle = start + vel_msg.angular.z*(t1-t0);
		}
	}	
	vel_msg.angular.z = 0;
	vel_pub.publish(vel_msg);
}

