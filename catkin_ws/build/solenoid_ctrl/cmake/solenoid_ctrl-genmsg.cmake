# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "solenoid_ctrl: 1 messages, 0 services")

set(MSG_I_FLAGS "-Isolenoid_ctrl:/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(solenoid_ctrl_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_custom_target(_solenoid_ctrl_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "solenoid_ctrl" "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(solenoid_ctrl
  "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/solenoid_ctrl
)

### Generating Services

### Generating Module File
_generate_module_cpp(solenoid_ctrl
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/solenoid_ctrl
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(solenoid_ctrl_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(solenoid_ctrl_generate_messages solenoid_ctrl_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_dependencies(solenoid_ctrl_generate_messages_cpp _solenoid_ctrl_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(solenoid_ctrl_gencpp)
add_dependencies(solenoid_ctrl_gencpp solenoid_ctrl_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS solenoid_ctrl_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(solenoid_ctrl
  "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/solenoid_ctrl
)

### Generating Services

### Generating Module File
_generate_module_eus(solenoid_ctrl
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/solenoid_ctrl
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(solenoid_ctrl_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(solenoid_ctrl_generate_messages solenoid_ctrl_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_dependencies(solenoid_ctrl_generate_messages_eus _solenoid_ctrl_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(solenoid_ctrl_geneus)
add_dependencies(solenoid_ctrl_geneus solenoid_ctrl_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS solenoid_ctrl_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(solenoid_ctrl
  "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/solenoid_ctrl
)

### Generating Services

### Generating Module File
_generate_module_lisp(solenoid_ctrl
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/solenoid_ctrl
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(solenoid_ctrl_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(solenoid_ctrl_generate_messages solenoid_ctrl_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_dependencies(solenoid_ctrl_generate_messages_lisp _solenoid_ctrl_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(solenoid_ctrl_genlisp)
add_dependencies(solenoid_ctrl_genlisp solenoid_ctrl_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS solenoid_ctrl_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(solenoid_ctrl
  "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/solenoid_ctrl
)

### Generating Services

### Generating Module File
_generate_module_nodejs(solenoid_ctrl
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/solenoid_ctrl
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(solenoid_ctrl_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(solenoid_ctrl_generate_messages solenoid_ctrl_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_dependencies(solenoid_ctrl_generate_messages_nodejs _solenoid_ctrl_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(solenoid_ctrl_gennodejs)
add_dependencies(solenoid_ctrl_gennodejs solenoid_ctrl_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS solenoid_ctrl_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(solenoid_ctrl
  "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/solenoid_ctrl
)

### Generating Services

### Generating Module File
_generate_module_py(solenoid_ctrl
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/solenoid_ctrl
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(solenoid_ctrl_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(solenoid_ctrl_generate_messages solenoid_ctrl_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rss-user-2/catkin_ws/src/solenoid_ctrl/msg/solenoid_status.msg" NAME_WE)
add_dependencies(solenoid_ctrl_generate_messages_py _solenoid_ctrl_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(solenoid_ctrl_genpy)
add_dependencies(solenoid_ctrl_genpy solenoid_ctrl_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS solenoid_ctrl_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/solenoid_ctrl)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/solenoid_ctrl
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(solenoid_ctrl_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/solenoid_ctrl)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/solenoid_ctrl
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(solenoid_ctrl_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/solenoid_ctrl)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/solenoid_ctrl
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(solenoid_ctrl_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/solenoid_ctrl)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/solenoid_ctrl
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(solenoid_ctrl_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/solenoid_ctrl)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/solenoid_ctrl\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/solenoid_ctrl
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(solenoid_ctrl_generate_messages_py std_msgs_generate_messages_py)
endif()
