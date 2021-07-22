// Generated by gencpp from file model_push/imu.msg
// DO NOT EDIT!


#ifndef MODEL_PUSH_MESSAGE_IMU_H
#define MODEL_PUSH_MESSAGE_IMU_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Accel.h>

namespace model_push
{
template <class ContainerAllocator>
struct imu_
{
  typedef imu_<ContainerAllocator> Type;

  imu_()
    : pose()
    , velocity()
    , acceleration()  {
    }
  imu_(const ContainerAllocator& _alloc)
    : pose(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::geometry_msgs::Accel_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;





  typedef boost::shared_ptr< ::model_push::imu_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::model_push::imu_<ContainerAllocator> const> ConstPtr;

}; // struct imu_

typedef ::model_push::imu_<std::allocator<void> > imu;

typedef boost::shared_ptr< ::model_push::imu > imuPtr;
typedef boost::shared_ptr< ::model_push::imu const> imuConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::model_push::imu_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::model_push::imu_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::model_push::imu_<ContainerAllocator1> & lhs, const ::model_push::imu_<ContainerAllocator2> & rhs)
{
  return lhs.pose == rhs.pose &&
    lhs.velocity == rhs.velocity &&
    lhs.acceleration == rhs.acceleration;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::model_push::imu_<ContainerAllocator1> & lhs, const ::model_push::imu_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace model_push

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::model_push::imu_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::model_push::imu_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::model_push::imu_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::model_push::imu_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::model_push::imu_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::model_push::imu_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::model_push::imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d3c213cdb4382c43adbff1f2dd2cf669";
  }

  static const char* value(const ::model_push::imu_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd3c213cdb4382c43ULL;
  static const uint64_t static_value2 = 0xadbff1f2dd2cf669ULL;
};

template<class ContainerAllocator>
struct DataType< ::model_push::imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "model_push/imu";
  }

  static const char* value(const ::model_push::imu_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::model_push::imu_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose pose\n"
"geometry_msgs/Twist velocity\n"
"geometry_msgs/Accel acceleration\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Accel\n"
"# This expresses acceleration in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
;
  }

  static const char* value(const ::model_push::imu_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::model_push::imu_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose);
      stream.next(m.velocity);
      stream.next(m.acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct imu_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::model_push::imu_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::model_push::imu_<ContainerAllocator>& v)
  {
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Accel_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MODEL_PUSH_MESSAGE_IMU_H
