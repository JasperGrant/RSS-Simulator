#!/usr/bin/env python

import rospy # rospy library needed for creating python based nodes
import sys, termios, tty # libraries needed to register key press instances
import subprocess # library needed to adjust the keyboard auto repeat delay and rate parameters

# import standard message types needed for publishers/subscribers
from std_msgs.msg import String # used to publish the key_pub message on the the /key_pub topic
from std_msgs.msg import Bool   # used to publish the key_ctrl message on the /key_ctrl topic

class Main:

	# class method used to initialize variables once when the program starts
	def __init__(self):

		# variable(s)
		self.settings = termios.tcgetattr(sys.stdin) # settings needed for system input
		self.control = False # control mode variable (True = control mode)
		self.new_instance = False # tracking variable for detecting new key press instances
		self.key = '' # placeholder variable for key press instance

		# publisher(s)
		self.key_ctrl = rospy.Publisher('key_ctrl', Bool, queue_size=1) # publisher on \key_ctrl topic
		self.key_pub = rospy.Publisher('key_pub', String, queue_size=1) # publisher on \key_pub topic

		# rate(s)
		key_rate  = 300 # rate for getKey method, specified in Hz
		pub_rate  = 100 # rate for publisher method, specified in Hz

		# timer(s), used to control method loop frequencies as defined by the rate(s)
		self.key_timer = rospy.Timer(rospy.Duration(1.0/key_rate), self.getKey)
		self.pub_timer = rospy.Timer(rospy.Duration(1.0/pub_rate), self.key_publisher)

	# class method used to read key press instance from the keyboard
	def getKey(self, key_timer):

		tty.setraw(sys.stdin.fileno()) # set up keyboard input in terminal
		self.key = sys.stdin.read(1)   # read keypress instance into self.key variable
									   # method halted here until a new key press instance occurs
		termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings) # reset system input?
		self.new_instance = True # register that a new key press instance has occured

		# continuosly check for ctrl-c input to exit node
		if (self.key == '\x03'):
			self.new_instance = False
			subprocess.Popen(['xset','r','rate','300','25']) # reset autorepeat parameters
			rospy.signal_shutdown('Exiting Node')

		# switch out of control mode when the space bar is pressed
		elif (self.key == ' ' and self.control == True):
			subprocess.Popen(['xset','r','rate','300','25']) # reset autorepeat parameters
			self.control = False

		# switch into control mode when the Enter key is pressed
		elif (self.key == '\r' and self.control == False):
			subprocess.Popen(['xset','r','rate','25','10'])  # adjust autorepeat parameters
			self.control = True
	
	# class method used to publish key_ctrl and key_pub messages
	def key_publisher(self, pub_timer):

		# always publish key_ctrl message
		self.key_ctrl.publish(self.control)

		# publish key_pub message if new keypress instance occurs while in control mode
		if (self.new_instance == True and self.control == True):
			self.key_pub.publish(self.key)

		# reset the new_instance variable
		self.new_instance = False

if __name__ == '__main__': 
    
	rospy.init_node('key_sub', anonymous=True) # initialize ROS node once

	try:

		Main() # create class object
		rospy.spin() # loop until shutdown signal

	except rospy.ROSInterruptException:
		pass
