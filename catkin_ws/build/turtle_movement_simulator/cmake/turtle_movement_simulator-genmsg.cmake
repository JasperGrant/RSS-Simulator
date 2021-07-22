# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "turtle_movement_simulator: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iturtle_movement_simulator:/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(turtle_movement_simulator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_custom_target(_turtle_movement_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtle_movement_simulator" "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" "geometry_msgs/Twist:geometry_msgs/Vector3:geometry_msgs/Pose:geometry_msgs/Accel:geometry_msgs/Point:geometry_msgs/Quaternion"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(turtle_movement_simulator
  "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtle_movement_simulator
)

### Generating Services

### Generating Module File
_generate_module_cpp(turtle_movement_simulator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtle_movement_simulator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(turtle_movement_simulator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(turtle_movement_simulator_generate_messages turtle_movement_simulator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_dependencies(turtle_movement_simulator_generate_messages_cpp _turtle_movement_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtle_movement_simulator_gencpp)
add_dependencies(turtle_movement_simulator_gencpp turtle_movement_simulator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtle_movement_simulator_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(turtle_movement_simulator
  "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtle_movement_simulator
)

### Generating Services

### Generating Module File
_generate_module_eus(turtle_movement_simulator
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtle_movement_simulator
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(turtle_movement_simulator_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(turtle_movement_simulator_generate_messages turtle_movement_simulator_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_dependencies(turtle_movement_simulator_generate_messages_eus _turtle_movement_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtle_movement_simulator_geneus)
add_dependencies(turtle_movement_simulator_geneus turtle_movement_simulator_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtle_movement_simulator_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(turtle_movement_simulator
  "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtle_movement_simulator
)

### Generating Services

### Generating Module File
_generate_module_lisp(turtle_movement_simulator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtle_movement_simulator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(turtle_movement_simulator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(turtle_movement_simulator_generate_messages turtle_movement_simulator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_dependencies(turtle_movement_simulator_generate_messages_lisp _turtle_movement_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtle_movement_simulator_genlisp)
add_dependencies(turtle_movement_simulator_genlisp turtle_movement_simulator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtle_movement_simulator_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(turtle_movement_simulator
  "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtle_movement_simulator
)

### Generating Services

### Generating Module File
_generate_module_nodejs(turtle_movement_simulator
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtle_movement_simulator
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(turtle_movement_simulator_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(turtle_movement_simulator_generate_messages turtle_movement_simulator_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_dependencies(turtle_movement_simulator_generate_messages_nodejs _turtle_movement_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtle_movement_simulator_gennodejs)
add_dependencies(turtle_movement_simulator_gennodejs turtle_movement_simulator_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtle_movement_simulator_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(turtle_movement_simulator
  "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Accel.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtle_movement_simulator
)

### Generating Services

### Generating Module File
_generate_module_py(turtle_movement_simulator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtle_movement_simulator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(turtle_movement_simulator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(turtle_movement_simulator_generate_messages turtle_movement_simulator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/turtle_movement_simulator/msg/imu.msg" NAME_WE)
add_dependencies(turtle_movement_simulator_generate_messages_py _turtle_movement_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtle_movement_simulator_genpy)
add_dependencies(turtle_movement_simulator_genpy turtle_movement_simulator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtle_movement_simulator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtle_movement_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtle_movement_simulator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(turtle_movement_simulator_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtle_movement_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtle_movement_simulator
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(turtle_movement_simulator_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtle_movement_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtle_movement_simulator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(turtle_movement_simulator_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtle_movement_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtle_movement_simulator
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(turtle_movement_simulator_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtle_movement_simulator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtle_movement_simulator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtle_movement_simulator
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(turtle_movement_simulator_generate_messages_py geometry_msgs_generate_messages_py)
endif()
