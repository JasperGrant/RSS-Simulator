cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(model_push)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "-std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "-std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(catkin REQUIRED
	roscpp
	gazebo_ros
	geometry_msgs
	turtle_movement_simulator
	message_generation
)

find_package(gazebo REQUIRED
)

link_directories(${GAZEBO_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})

add_library(model_push SHARED model_push.cc)
target_link_libraries(model_push ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

add_library(Debris_IMU_plugin SHARED Debris_IMU_plugin.cc)
target_link_libraries(Debris_IMU_plugin ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})


add_library(imu_plugin SHARED imu_plugin.cc)
target_link_libraries(imu_plugin ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})


