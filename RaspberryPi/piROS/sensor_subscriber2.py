#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time

# Define user function
def callback(data):
        print(data.data)
        if data.data == 5:
                new()
                
def new():
        pub = rospy.Publisher("new_topic", String, queue_size=10)
        rate = rospy.Rate(2)
        data = "hello"
        pub.publish(data)
        rate.sleep()
        
# main
rospy.init_node("sensor_subscriber2")

try:
        sub1 = rospy.Subscriber("counter", Int32, callback)
        print('')
        sub2 = rospy.Subscriber("distance", String, callback)
        
        
        
                
                
        rospy.spin()
        
except rospy.ROSInterruptException:
        print("Interrupt!!")
