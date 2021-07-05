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
                led()
                
def led():
        print("good")
        # Setting pin number
        pin_LED_Blue = 4
        
        # GPIO mode setting
        GPIO.setwarnings(False)
        GPIO.setmode(GPIO.BCM) # GPIOn Mode
        
        # GPIO pin setting
        GPIO.setup(pin_LED_Blue, GPIO.OUT)
        GPIO.output(pin_LED_Blue, 1)
        rospy.sleep(5)
        
# main
rospy.init_node("sensor_subscriber1")
rate = rospy.Rate(2)

try:
        sub1 = rospy.Subscriber("counter", Int32, callback)
        print('')
        sub2 = rospy.Subscriber("distance", String, callback)
        
        
        
                
                
        rospy.spin()
        
except rospy.ROSInterruptException:
        print("Interrupt!!")
