
(cl:in-package :asdf)

(defsystem "solenoid_ctrl-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "solenoid_status" :depends-on ("_package_solenoid_status"))
    (:file "_package_solenoid_status" :depends-on ("_package"))
  ))