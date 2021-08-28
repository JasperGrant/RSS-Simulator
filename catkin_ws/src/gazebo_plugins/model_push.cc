#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <thread>
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/convert.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#define PI 3.141592654

namespace gazebo{
	
	class ModelPush : public ModelPlugin{
		public: ModelPush(){}

		public: float forceappliedrotation = 0.3, forceappliedtranslation = 0.3, IMUangle;
		public:int xReading, yReading, zReading, PWM = 0;

		public: void OnRosMsg(const geometry_msgs::Twist::ConstPtr& vel_msg){
			if(vel_msg->linear.x or vel_msg->linear.y or vel_msg->angular.z){
				model->WorldPose().Rot().X();
				float placeholder =  atan2(2.0f * (model->WorldPose().Rot().X() * model->WorldPose().Rot().Z() + model->WorldPose().Rot().X() * model->WorldPose().Rot().Y()), model->WorldPose().Rot().W() * model->WorldPose().Rot().W() + model->WorldPose().Rot().X() * model->WorldPose().Rot().X() - model->WorldPose().Rot().Y() * model->WorldPose().Rot().Y() - model->WorldPose().Rot().Z() * model->WorldPose().Rot().Z())+PI/2;
				while(placeholder<0){
					 placeholder += 2*PI;
				}
				IMUangle = placeholder;
			}
			xReading = vel_msg->linear.x;
			yReading = vel_msg->linear.y;
			zReading = vel_msg->angular.z;
			

		}
		public : void update(void){
			while(ros::ok()){
				if(xReading > 0){

					model->GetLink("link_1_clone_0")->AddForce(ignition::math::Vector3d(forceappliedtranslation*cos(IMUangle), forceappliedtranslation*sin(IMUangle), 0));
					model->GetLink("link_1_clone_1")->AddForce(ignition::math::Vector3d(forceappliedtranslation*cos(IMUangle), forceappliedtranslation*sin(IMUangle), 0));	
				}
				if(xReading<0){
					ROS_INFO("Breaks initiated");
					model->GetLink("link_1_clone_4")->AddForce(ignition::math::Vector3d(-forceappliedtranslation*cos(IMUangle), -forceappliedtranslation*sin(IMUangle), 0));
					model->GetLink("link_1_clone_5")->AddForce(ignition::math::Vector3d(-forceappliedtranslation*cos(IMUangle), -forceappliedtranslation*sin(IMUangle), 0));
				}
				if(yReading<0){
					model->GetLink("link_1_clone_2")->AddForce(ignition::math::Vector3d(forceappliedtranslation*sin(IMUangle), forceappliedtranslation*cos(IMUangle), 0));
					model->GetLink("link_1_clone_3")->AddForce(ignition::math::Vector3d(forceappliedtranslation*sin(IMUangle), forceappliedtranslation*cos(IMUangle), 0));
				}
				if(yReading>0){
					model->GetLink("link_1_clone")->AddForce(ignition::math::Vector3d(-forceappliedtranslation*sin(IMUangle), -forceappliedtranslation*cos(IMUangle), 0));
					model->GetLink("link_1")     ->AddForce(ignition::math::Vector3d(-forceappliedtranslation*sin(IMUangle), -forceappliedtranslation*cos(IMUangle), 0));
				}

				if(zReading>0){
					model->GetLink("link_1_clone_2")->AddRelativeForce(ignition::math::Vector3d(0, -forceappliedrotation * zReading, 0));
					model->GetLink("link_1")     ->AddRelativeForce(ignition::math::Vector3d(0, forceappliedrotation * zReading, 0));
				}

				else if(zReading<0){
	//Signs are negative what you would think because vel_msg->angular.z is negative.
					model->GetLink("link_1_clone_3")->AddRelativeForce(ignition::math::Vector3d(0, forceappliedrotation * zReading, 0));
					model->GetLink("link_1_clone")->AddRelativeForce(ignition::math::Vector3d(0, -forceappliedrotation * zReading, 0));
				}
				else{
					model->GetLink("link_1_clone_2")->AddRelativeForce(ignition::math::Vector3d(0, 0, 0));
					model->GetLink("link_1")->AddRelativeForce(ignition::math::Vector3d(0, 0, 0));
					model->GetLink("link_1_clone_3")->AddRelativeForce(ignition::math::Vector3d(0, 0, 0));
					model->GetLink("link_1_clone")->AddRelativeForce(ignition::math::Vector3d(0, 0, 0));
				}
			}
		}
		
		private: void QueueThread(){
			static const double timeout = 0.01;
			while(this->rosNode->ok()){
				this->rosQueue.callAvailable(ros::WallDuration(timeout));
			}
		}

		public : void Load(physics :: ModelPtr _parent, sdf :: ElementPtr /*_sdf*/){ 
			std::thread iterationThread = std::thread(std::bind(&ModelPush::update, this));
			iterationThread.detach();
			ROS_INFO("Movement Plugin Loaded Successfully\n");
			this->model = _parent;
			if(!ros::isInitialized()){
				int argc = 0;
				char** argv = NULL;
				ros::init(argc, argv, "gazebo_node");
				ros::init_options::NoSigintHandler;
			}
			
			this->rosNode.reset(new ros::NodeHandle("gazebo_client"));

			ros::SubscribeOptions so = ros::SubscribeOptions::create<geometry_msgs::Twist>("/turtle1/cmd_vel", 10000, boost::bind(&ModelPush::OnRosMsg, this, _1), ros::VoidPtr(), &this->rosQueue);
			
			this->rosSub = this->rosNode->subscribe(so);
			
			this->rosQueueThread = std::thread(std::bind(&ModelPush::QueueThread, this));



		}

		private: physics :: ModelPtr model;
		private: std::unique_ptr<ros::NodeHandle> rosNode;
		private: ros::Subscriber rosSub;
		private: ros::CallbackQueue rosQueue;
		private: std::thread rosQueueThread;

	};
	GZ_REGISTER_MODEL_PLUGIN(ModelPush)
} 
