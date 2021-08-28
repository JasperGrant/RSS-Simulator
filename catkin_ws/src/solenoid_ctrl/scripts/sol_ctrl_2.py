#!/usr/bin/env python

import rospy # rospy library needed for creating python based nodes

# import standard message types needed for publishers/subscribers
from std_msgs.msg import Int16
from std_msgs.msg import Bool

# import custom message type needed for publishers/subscribers
from solenoid_ctrl.msg import solenoid_status
from sensor_msgs.msg import Joy

class Main:

	# class method used to initialize variables once when the program starts
	def __init__(self):

		# variable(s)
		self.cmd_thrust = 0 # initialize the cmd_thrust command as zero-input
		self.cmd_bear = False # initialize the cmd_bear command as false
		self.new_instance = False # tracking variable for detecting new input messages from key_sub.py
		self.new_bear = False # tracking variable for detecting a change of state from key_sub.py

		self.status = solenoid_status() # initialize status variable using the solenoid_status format
		self.status.sol_ctrl = True # initialize the control mode as False
		self.status.sol_bear = True # initialize the air bearing state as false
		self.status.sol_thrust = [0, 0, 0, 0, 0, 0, 0, 0] # initialize thruster states as zero-input
		# subscriber(s), with specified topic, message type, and class callback method
		rospy.Subscriber('joy', Joy, self.joy_cb)
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

	#class callback that takes in input from controller and decides which button has been pressed
	def joy_cb(self, msg):

		self.leftAxisX = msg.axes[0]
		self.aButton = msg.buttons[0]
		self.new_instance = True # register that a new command has been received

		if (self.leftAxisX > 0.5): # left stick has been moved in positive direction
			self.cmd_thrust = 6

		elif (self.leftAxisX < -0.5): # left stick has been moved in negative direction
			self.cmd_thrust = 3

		elif (self.aButton == 1.0): # a button has been pressed so toggle true/false
			if self.new_bear == False:
				self.new_bear = True
			elif self.new_bear == True:
				self.new_bear = False

		else: # reset if nothing has been pressed
			self.cmd_thrust = 0

	# class callback method which subscribes to the /sol_bear topic (directly from Arduino)
	def bear_cb(self, msg):

		self.status.sol_bear = msg.data # update status of air bearing valve

	# class callback method which subscribes to the /sol_thrust topic (directly from Arduino)
	def thrust_cb(self, msg):
		if self.cmd_thrust!=0: # turn on a thruster corresponding to a button pressed
			self.status.sol_thrust = [0, 0, 0, 0, 0, 0, 0, 0]
			self.status.sol_thrust[self.cmd_thrust-1] = 1
		else: # reset all 8 thrusters to off
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
