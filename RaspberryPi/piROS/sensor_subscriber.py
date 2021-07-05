#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time

# Define user function
def callback(data):
        print(data.data)

# main
rospy.init_node("sensor_subscriber")

sub1 = rospy.Subscriber("counter", Int32, callback)
print('')
sub2 = rospy.Subscriber("distance", String, callback)

rospy.spin()
