;; Auto-generated. Do not edit!


(when (boundp 'solenoid_ctrl::solenoid_status)
  (if (not (find-package "SOLENOID_CTRL"))
    (make-package "SOLENOID_CTRL"))
  (shadow 'solenoid_status (find-package "SOLENOID_CTRL")))
(unless (find-package "SOLENOID_CTRL::SOLENOID_STATUS")
  (make-package "SOLENOID_CTRL::SOLENOID_STATUS"))

(in-package "ROS")
;;//! \htmlinclude solenoid_status.msg.html


(defclass solenoid_ctrl::solenoid_status
  :super ros::object
  :slots (_sol_ctrl _sol_bear _sol_thrust ))

(defmethod solenoid_ctrl::solenoid_status
  (:init
   (&key
    ((:sol_ctrl __sol_ctrl) nil)
    ((:sol_bear __sol_bear) nil)
    ((:sol_thrust __sol_thrust) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _sol_ctrl __sol_ctrl)
   (setq _sol_bear __sol_bear)
   (setq _sol_thrust __sol_thrust)
   self)
  (:sol_ctrl
   (&optional __sol_ctrl)
   (if __sol_ctrl (setq _sol_ctrl __sol_ctrl)) _sol_ctrl)
  (:sol_bear
   (&optional __sol_bear)
   (if __sol_bear (setq _sol_bear __sol_bear)) _sol_bear)
  (:sol_thrust
   (&optional __sol_thrust)
   (if __sol_thrust (setq _sol_thrust __sol_thrust)) _sol_thrust)
  (:serialization-length
   ()
   (+
    ;; bool _sol_ctrl
    1
    ;; bool _sol_bear
    1
    ;; int16[] _sol_thrust
    (* 2    (length _sol_thrust)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _sol_ctrl
       (if _sol_ctrl (write-byte -1 s) (write-byte 0 s))
     ;; bool _sol_bear
       (if _sol_bear (write-byte -1 s) (write-byte 0 s))
     ;; int16[] _sol_thrust
     (write-long (length _sol_thrust) s)
     (dotimes (i (length _sol_thrust))
       (write-word (elt _sol_thrust i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _sol_ctrl
     (setq _sol_ctrl (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _sol_bear
     (setq _sol_bear (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int16[] _sol_thrust
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _sol_thrust (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _sol_thrust i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;;
   self)
  )

(setf (get solenoid_ctrl::solenoid_status :md5sum-) "f071f78c9fde6c43f4fb013e9d377f82")
(setf (get solenoid_ctrl::solenoid_status :datatype-) "solenoid_ctrl/solenoid_status")
(setf (get solenoid_ctrl::solenoid_status :definition-)
      "# Reports the solenoid and control state of the solenoid_ctrl package
bool sol_ctrl        # indicates whether key_sub is in control mode
bool sol_bear        # indicates the status of the air bearing solenoid valve
int16[] sol_thrust   # indicates the status of the thruster air bearings


")



(provide :solenoid_ctrl/solenoid_status "f071f78c9fde6c43f4fb013e9d377f82")


