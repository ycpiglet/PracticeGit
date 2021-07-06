#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time

# Define user function
def callback(data):
        msg_list.append(data.data)
        print(msg_list)

def callback_Int(data):
        print(data.data)
        if data.data == 5:
                new()
                
def callback_String(data):
        print(data.data)
                
def new():
        pub = rospy.Publisher("new_topic", String, queue_size=10)
        rate = rospy.Rate(2)
        data = "hello"
        pub.publish(data)
        rate.sleep()
        
# main
rospy.init_node("sensor_subscriber2")
msg_list = list()

try:
        sub1 = rospy.Subscriber("counter", Int32, callback)
        sub2 = rospy.Subscriber("distance", String, callback_String)
        
        rospy.spin()
        
except rospy.ROSInterruptException:
        print("Interrupt!!")
