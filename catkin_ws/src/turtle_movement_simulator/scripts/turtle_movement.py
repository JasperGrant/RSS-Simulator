#!/usr/bin/env python

import rospy
import math
from geometry_msgs.msg import Twist
PI = 3.141592654

#initialize node, publisher, and message type.
rospy.init_node('movement_node', anonymous=True)
vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
vel_msg = Twist()

#function which takes a distance and then moves the turtle that far in a straight direction
def translate(distance):
	vel_msg.linear.x = 1
	t0 = rospy.Time.now().to_sec()
	current_distance=0
	while(current_distance < distance):
		vel_pub.publish(vel_msg)
		t1 = rospy.Time.now().to_sec()
		current_distance = vel_msg.linear.x*(t1-t0)
	vel_msg.linear.x = 0
	vel_pub.publish(vel_msg)

#function which takes start and ending positions to rotate the turtle. The turtle will rotate in the shortest way possible.
def rotate(start, end):
	vel_msg.angular.z = 1
	t0 = rospy.Time.now().to_sec()
	if start > 2*PI:
		start-=2*PI
	if end > 2*PI:
		end-=2*PI
	if end - start < PI and end > start:
		vel_msg.angular.z = 1
		current_angle = start
		while(current_angle < end):
			vel_pub.publish(vel_msg)
			t1 = rospy.Time.now().to_sec()
			current_angle = start + vel_msg.angular.z*(t1-t0)
	elif start-end < PI and start > end:
		vel_msg.angular.z = -1
		current_angle = start
		while(current_angle > end):
			vel_pub.publish(vel_msg)
			t1 = rospy.Time.now().to_sec()
			current_angle = start + vel_msg.angular.z*(t1-t0)
	elif start > end:
		end+=2*PI
		vel_msg.angular.z = 1
		current_angle = start
		while(current_angle < end):
			vel_pub.publish(vel_msg)
			t1 = rospy.Time.now().to_sec()
			current_angle = start + vel_msg.angular.z*(t1-t0)
	elif end > start:
		start+=2*PI
		vel_msg.angular.z = -1
		current_angle = start
		while(current_angle > end):
			vel_pub.publish(vel_msg)
			t1 = rospy.Time.now().to_sec()
			current_angle = start + vel_msg.angular.z*(t1-t0)
	elif start == end:
		pass
	vel_msg.angular.z = 0
	vel_pub.publish(vel_msg)	

#function which calculates polar coordinates based off of cartesian coordinates. It also needs the current angle so that it can return the original angle if no change.
def distanceanglefinder(coordX, coordY, current_angle):
	distance = abs(math.sqrt(pow(coordX,2) + pow(coordY,2)))
	if coordX == 0 and coordY == 0:
		angle = current_angle
	elif coordX == 0:
		if coordY<0:
			angle = -PI/2
		else:
			angle = PI/2
	elif coordX < 0:
		angle = math.atan(coordY/coordX)+PI	
	else:
		angle = math.atan(coordY/coordX)
	if angle < 0:
		angle+=2*PI
	return distance, angle

firsttime = True
#first mode I programmed in which the turtle is given a single position, moves to it, and then turns to 0 degrees.
def singlecoordinate():
	global firsttime
	if firsttime:
		oldcoordX = 0.0
		oldcoordY = 0.0
		firsttime = False
	while True:
		newcoordX, newcoordY = input("Enter coordinates in format X , Y:")
		newcoordX = float(newcoordX)
		newcoordY = float(newcoordY)
		distance, angle = distanceanglefinder(newcoordX - oldcoordX, newcoordY - oldcoordY, 0)
		print(newcoordX - oldcoordX)
		print(newcoordY - oldcoordY)
		oldcoordX = newcoordX
		oldcoordY = newcoordY
		rotate(2*PI, angle)
		translate(distance)
		rotate(angle, 2*PI)

#second mode I programmed in which the turtle moves through a list of movement commands without switching it's angle to 0 in between. After the final command it will rotate to 0.
def coordinatelist():
	global firsttime
	if firsttime:
		oldcoordX = 0.0
		oldcoordY = 0.0
		firsttime = False
	while True:
		i = 0
		newcoordX = 0.0
		newcoordY = 0.0
		relativecoords = [[0 for i in range(2)] for j in range(20)]
		while(newcoordX!=99 or newcoordY!=99):
			newcoordX, newcoordY = input("Enter coordinate to add to list in format X , Y:\n 99, 99 to quit\n")
			relativecoords[i][0] = float(newcoordX - oldcoordX)
			relativecoords[i][1] = float(newcoordY - oldcoordY)
			oldcoordX = newcoordX
			oldcoordY = newcoordY
			i+=1
		current_angle = 0
		j=0
		while j < i-1:
			distance, angle = distanceanglefinder(relativecoords[j][0], relativecoords[j][1], current_angle)
			print(relativecoords[j][0])
			print(relativecoords[j][1])
			rotate(current_angle, angle) 
			current_angle = angle
			translate(distance)
			j+=1
		rotate(current_angle, 2*PI)

#function which decides mode of program.
def move():
	while not rospy.is_shutdown():
		prompt = input("Choose mode:\n1. Single Coordinate\n2. Coordinate List\n")
		if prompt == 1:
			singlecoordinate()
		if prompt == 2:
			coordinatelist()

#main exception checker.
if __name__ == '__main__':
	try:
		print(rospy.Time.now().to_sec())
		move()
	except rospy.ROSInterruptException:
		pass
