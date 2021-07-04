#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time

# ROS setting
rospy.init_node("topic_led")
pub = rospy.Publisher('counter', Int32, queue_size=10)
rate = rospy.Rate(2)

# main
count = 0

while not rospy.is_shutdown():
    # Setting pin number
    pin_LED_Red = 4
    pin_LED_Blue = 3
    pin_GND = 6

    # GPIO mode setting
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM) # GPIOn Mode

    # GPIO pin setting
    GPIO.setup(pin_LED_Red, GPIO.OUT)
    GPIO.setup(pin_LED_Blue, GPIO.OUT)
    
    pub.publish(count)
    GPIO.output(pin_LED_Red, 1)
    time.sleep(1)
    GPIO.output(pin_LED_Red, 0)
    time.sleep(1)
    count += 1
    print("Blink! "+str(count))
    
    if count == 4:
        GPIO.output(pin_LED_Blue, 1)
        
    if count == 8:
        GPIO.output(pin_LED_Blue, 0)
        
    rate.sleep()

    GPIO.cleanup()      # Reset GPIO
