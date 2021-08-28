; Auto-generated. Do not edit!


(cl:in-package solenoid_ctrl-msg)


;//! \htmlinclude solenoid_status.msg.html

(cl:defclass <solenoid_status> (roslisp-msg-protocol:ros-message)
  ((sol_ctrl
    :reader sol_ctrl
    :initarg :sol_ctrl
    :type cl:boolean
    :initform cl:nil)
   (sol_bear
    :reader sol_bear
    :initarg :sol_bear
    :type cl:boolean
    :initform cl:nil)
   (sol_thrust
    :reader sol_thrust
    :initarg :sol_thrust
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass solenoid_status (<solenoid_status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <solenoid_status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'solenoid_status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name solenoid_ctrl-msg:<solenoid_status> is deprecated: use solenoid_ctrl-msg:solenoid_status instead.")))

(cl:ensure-generic-function 'sol_ctrl-val :lambda-list '(m))
(cl:defmethod sol_ctrl-val ((m <solenoid_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader solenoid_ctrl-msg:sol_ctrl-val is deprecated.  Use solenoid_ctrl-msg:sol_ctrl instead.")
  (sol_ctrl m))

(cl:ensure-generic-function 'sol_bear-val :lambda-list '(m))
(cl:defmethod sol_bear-val ((m <solenoid_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader solenoid_ctrl-msg:sol_bear-val is deprecated.  Use solenoid_ctrl-msg:sol_bear instead.")
  (sol_bear m))

(cl:ensure-generic-function 'sol_thrust-val :lambda-list '(m))
(cl:defmethod sol_thrust-val ((m <solenoid_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader solenoid_ctrl-msg:sol_thrust-val is deprecated.  Use solenoid_ctrl-msg:sol_thrust instead.")
  (sol_thrust m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <solenoid_status>) ostream)
  "Serializes a message object of type '<solenoid_status>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'sol_ctrl) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'sol_bear) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sol_thrust))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    ))
   (cl:slot-value msg 'sol_thrust))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <solenoid_status>) istream)
  "Deserializes a message object of type '<solenoid_status>"
    (cl:setf (cl:slot-value msg 'sol_ctrl) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'sol_bear) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'sol_thrust) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'sol_thrust)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<solenoid_status>)))
  "Returns string type for a message object of type '<solenoid_status>"
  "solenoid_ctrl/solenoid_status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'solenoid_status)))
  "Returns string type for a message object of type 'solenoid_status"
  "solenoid_ctrl/solenoid_status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<solenoid_status>)))
  "Returns md5sum for a message object of type '<solenoid_status>"
  "f071f78c9fde6c43f4fb013e9d377f82")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'solenoid_status)))
  "Returns md5sum for a message object of type 'solenoid_status"
  "f071f78c9fde6c43f4fb013e9d377f82")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<solenoid_status>)))
  "Returns full string definition for message of type '<solenoid_status>"
  (cl:format cl:nil "# Reports the solenoid and control state of the solenoid_ctrl package~%bool sol_ctrl        # indicates whether key_sub is in control mode~%bool sol_bear        # indicates the status of the air bearing solenoid valve~%int16[] sol_thrust   # indicates the status of the thruster air bearings~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'solenoid_status)))
  "Returns full string definition for message of type 'solenoid_status"
  (cl:format cl:nil "# Reports the solenoid and control state of the solenoid_ctrl package~%bool sol_ctrl        # indicates whether key_sub is in control mode~%bool sol_bear        # indicates the status of the air bearing solenoid valve~%int16[] sol_thrust   # indicates the status of the thruster air bearings~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <solenoid_status>))
  (cl:+ 0
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sol_thrust) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <solenoid_status>))
  "Converts a ROS message object to a list"
  (cl:list 'solenoid_status
    (cl:cons ':sol_ctrl (sol_ctrl msg))
    (cl:cons ':sol_bear (sol_bear msg))
    (cl:cons ':sol_thrust (sol_thrust msg))
))
