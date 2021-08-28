#!/usr/bin/env python

import rospy # rospy library needed for creating python based nodes

# import standard message types needed for publishers/subscribers
from std_msgs.msg import String
from std_msgs.msg import Int16
from std_msgs.msg import Bool

# import custom message type needed for publishers/subscribers
from solenoid_ctrl.msg import solenoid_status

class Main:

	# class method used to initialize variables once when the program starts
	def __init__(self):

		# variable(s)
		self.cmd_thrust = 0 # initialize the cmd_thrust command as zero-input
		self.cmd_bear = False # initialize the cmd_bear command as false
		self.new_instance = False # tracking variable for detecting new input messages from key_sub.py
		self.new_bear = False # tracking variable for detecting a change of state from key_sub.py

		self.status = solenoid_status() # initialize status variable using the solenoid_status format
		self.status.sol_ctrl = False # initialize the control mode as False
		self.status.sol_bear = False # initialize the air bearing state as false
		self.status.sol_thrust = [0, 0, 0, 0, 0, 0, 0, 0] # initialize thruster states as zero-input

		self.key = String() # initialize key variable using the String format

		# subscriber(s), with specified topic, message type, and class callback method
		rospy.Subscriber('key_ctrl', Bool, self.ctrl_cb)
		rospy.Subscriber('key_pub', String, self.key_cb)
		rospy.Subscriber('sol_bear', Bool, self.bear_cb)
		rospy.Subscriber('sol_thrust', Int16, self.thrust_cb)

		# publisher(s), with specified topic, message type, and queue_size
		self.thrust_pub = rospy.Publisher('cmd_thrust', Int16, queue_size=1)
		self.bear_pub = rospy.Publisher('cmd_bear', Bool, queue_size=1)
		self.status_pub = rospy.Publisher('sol_status', solenoid_status, queue_size=1)

		# rate(s)
		pub_rate = 10 # rate for the publisher method, specified in Hz

		# timer(s), used to control method loop frequencies as defined by the rate(s)
		self.pub_timer = rospy.Timer(rospy.Duration(1.0/pub_rate), self.sol_publisher)


	# class callback method which subscribes to the /key_pub topic
	def key_cb(self, msg):

		self.key = msg.data # set key variable to message contents
		self.new_instance = True # register that a new key instance has been received

		# if new key instance corresponds to a thruster (numbered 1 - 8)
		# 	update cmd_thrust command to actuate the given thruster
		if (self.key in ['1','2','3','4','5','6','7','8']):
			self.cmd_thrust = int(self.key)

		# if new key instance corresponds to a air bearing state change input message
		# 	update new_bear variable to reflect requested state (False = off)
		elif (self.key == '9'):
			self.new_bear = False
			self.cmd_thrust = 0 # cmd_thrust = 0 while self.key is not in [1 - 8]

		# if new key instance corresponds to a air bearing state change input message
		# 	update new_bear variable to reflect requested state (True = on)
		elif (self.key == '0'):
			self.new_bear = True
			self.cmd_thrust = 0 # cmd_thrust = 0 while self.key is not in [1 - 8]

		# if new key instance does not correspond to a set command
		# 	set cmd_thrust command to zero-input (0 = all thrusters off)
		else:
			self.cmd_thrust = 0 # cmd_thrust = 0 while self.key is not in [1 - 8]

	# class callback method which subscribes to the /key_ctrl topic and updates the control
	#	mode state as part of the solenoid_status message
	def ctrl_cb(self, msg):

		self.status.sol_ctrl = msg.data

	# class callback method which subscribes to the /sol_bear topic (directly from Arduino)
	def bear_cb(self, msg):

		self.status.sol_bear = msg.data # update status of air bearing valve

	# class callback method which subscribes to the /sol_thrust topic (directly from Arduino)
	def thrust_cb(self, msg):

		# if message data is non-zero, update status of actuated thruster valve
		if (msg.data != 0):			
			index = msg.data - 1
			self.status.sol_thrust = [0, 0, 0, 0, 0, 0, 0, 0]
			self.status.sol_thrust[index] = 1

		# if message data is equal to zero, update thruster valve status as zero-input
		else:
			self.status.sol_thrust = [0, 0, 0, 0, 0, 0, 0, 0]

	def sol_publisher(self, pub_timer):

		# set cmd_thrust to zero if no message has been received by key_cb
		if (self.new_instance == False):
			self.cmd_thrust = 0

		# update cmd_bear and publish bear_pub message if there has been a change
		# 	of state received by key_cb
		if (self.new_bear != self.cmd_bear):
			self.cmd_bear = self.new_bear
			self.bear_pub.publish(self.cmd_bear)

		# always publish the cmd_thrust and status messages
		self.thrust_pub.publish(self.cmd_thrust)
		self.status_pub.publish(self.status)

		# reset the new_instance variable
		self.new_instance = False

if __name__ == '__main__': 
    
	rospy.init_node('sol_ctrl', anonymous=True) # initialize ROS node once

	try:
		Main() # create class object
		rospy.spin() # loop until shutdown signal

	except rospy.ROSInterruptException:
		pass
