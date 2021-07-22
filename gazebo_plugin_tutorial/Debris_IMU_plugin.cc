#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <thread>




namespace gazebo{
	
	class IMUd_Plugin : public ModelPlugin{
		public: IMUd_Plugin(){}

		public: void Load(physics :: ModelPtr _parent, sdf :: ElementPtr _sdf){
			ROS_INFO("Debris IMU Loaded Successfully\n");
			this->model = _parent;
			int argc = 0;
			char** argv = NULL;
			ros::init(argc, argv, "debris_publisher");

			
			std::thread IMUdThread (std::bind(&IMUd_Plugin::IMUd, this));
			IMUdThread.detach();

		}

		public: void IMUd(void){
			geometry_msgs::Pose pos;

			ros::NodeHandle nimud;

			ros::Publisher imud_pub = nimud.advertise<geometry_msgs::Pose>("debris_pose", 10);

			while(ros::ok()){

				ros::Rate loop_rate(1);

				pos.position.x = this->model->WorldPose().Pos().X();
				pos.position.y = this->model->WorldPose().Pos().Y();
				pos.position.z = this->model->WorldPose().Pos().Z();
				pos.orientation.x = this->model->WorldPose().Rot().X();
				pos.orientation.y = this->model->WorldPose().Rot().Y();
				pos.orientation.z = this->model->WorldPose().Rot().Z();
				pos.orientation.w = this->model->WorldPose().Rot().W();

				imud_pub.publish(pos);
				loop_rate.sleep();
				ros::spinOnce();
			}
				
				
		}
		private: physics :: ModelPtr model;
	};
	GZ_REGISTER_MODEL_PLUGIN(IMUd_Plugin);
} 
