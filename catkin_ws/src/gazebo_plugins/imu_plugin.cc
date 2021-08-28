#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Accel.h>
#include <geometry_msgs/Pose.h>
#include <thread>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/convert.h>
#include "turtle_movement_simulator/imu.h"



namespace gazebo{
	
	class IMU_Plugin : public ModelPlugin{
		public: IMU_Plugin(){}

		public: void Load(physics :: ModelPtr _parent, sdf :: ElementPtr _sdf){
			ROS_INFO("IMU Loaded Successfully\n");
			this->model = _parent;
			int argc = 0;
			char** argv = NULL;
			ros::init(argc, argv, "imu_publisher");

			
			std::thread IMUThread (std::bind(&IMU_Plugin::IMU, this));
			IMUThread.detach();

		}

		public: void IMU(void){
			geometry_msgs::TransformStamped transformStamped;
			geometry_msgs::Pose pos;
			geometry_msgs::Twist vel;
			geometry_msgs::Accel acc;

			ros::NodeHandle nimu;

			ros::Publisher imu_pub = nimu.advertise<turtle_movement_simulator::imu>("imu", 10);

			while(ros::ok()){
				static tf2_ros::TransformBroadcaster br;
				geometry_msgs::TransformStamped transformStamped;
			
				turtle_movement_simulator::imu Imu;
				transformStamped.header.stamp = ros::Time::now();
  				transformStamped.header.frame_id = "world";
  				transformStamped.child_frame_id = "rss";
				transformStamped.transform.translation.x = this->model->WorldPose().Pos().X();
				transformStamped.transform.translation.y = this->model->WorldPose().Pos().Y();
				transformStamped.transform.translation.z = this->model->WorldPose().Pos().Z();
				tf2::Quaternion q;
				q.setRPY(0, 0, 0);
				transformStamped.transform.rotation.x = this->model->WorldPose().Rot().X();
				transformStamped.transform.rotation.y = this->model->WorldPose().Rot().Y();
				transformStamped.transform.rotation.z = this->model->WorldPose().Rot().Z();
				transformStamped.transform.rotation.w = this->model->WorldPose().Rot().W();
				
				br.sendTransform(transformStamped);

				ros::Rate loop_rate(1);

				pos.position.x = this->model->WorldPose().Pos().X();
				pos.position.y = this->model->WorldPose().Pos().Y();
				pos.position.z = this->model->WorldPose().Pos().Z();
				pos.orientation.x = this->model->WorldPose().Rot().X();
				pos.orientation.y = this->model->WorldPose().Rot().Y();
				pos.orientation.z = this->model->WorldPose().Rot().Z();
				pos.orientation.w = this->model->WorldPose().Rot().W();

				vel.linear.x = this->model->RelativeLinearVel().Y(); //This is really weird but the simulator seems to have X and Y mixed up relatively. Easiest solution is to switch them and then fix if it is ever a problem
				vel.linear.y = this->model->RelativeLinearVel().X();
				vel.linear.z = this->model->RelativeLinearVel().Z();
				vel.angular.x = this->model->RelativeAngularVel().X();
				vel.angular.y = this->model->RelativeAngularVel().Y();
				vel.angular.z = this->model->RelativeAngularVel().Z();

				acc.linear.x = this->model->RelativeLinearAccel().Y(); //Same
				acc.linear.y = this->model->RelativeLinearAccel().X();
				acc.linear.z = this->model->RelativeLinearAccel().Z();
				acc.angular.x = this->model->RelativeAngularAccel().X();
				acc.angular.y = this->model->RelativeAngularAccel().Y();
				acc.angular.z = this->model->RelativeAngularAccel().Z();
		
				Imu.pose = pos;
				Imu.velocity = vel;
				Imu.acceleration = acc;
				imu_pub.publish(Imu);
				loop_rate.sleep();
				ros::spinOnce();
			}
				
				
		}
		private: physics :: ModelPtr model;
	};
	GZ_REGISTER_MODEL_PLUGIN(IMU_Plugin);
} 
