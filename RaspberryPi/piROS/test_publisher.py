#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import time

rospy.init_node("test_publisher")
pub = rospy.Publisher("topic", Int32, queue_size=10)
rate = rospy.Rate(2)

count = 0

while not rospy.is_shutdown():
	count += 1
	print("send message : %d"%count)
	pub.publish(count)
	rate.sleep()
