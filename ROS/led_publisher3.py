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

# while working rightly
while not rospy.is_shutdown():
    try:
        # Setting pin number
        pin_LED_Red = 2
        pin_LED_Green = 3
        pin_LED_Blue = 4
        pin_Trig = 27
        pin_Echo = 17
        pin_GND = 6

        # GPIO mode setting
        GPIO.setwarnings(False)
        GPIO.setmode(GPIO.BCM) # GPIOn Mode

        # GPIO pin setting
        GPIO.setup(pin_LED_Red, GPIO.OUT)
        GPIO.setup(pin_LED_Green, GPIO.OUT)
        GPIO.setup(pin_LED_Blue, GPIO.OUT)
        GPIO.setup(pin_Trig, GPIO.OUT)
        GPIO.setup(pin_Echo, GPIO.IN)
        
        pub.publish(count)
        
        GPIO.output(pin_Trig, False)
        
        GPIO.output(pin_Trig, True)
        time.sleep(0.00001)
        GPIO.output(pin_Trig, False)
        
        while GPIO.input(pin_Echo) == 0:
            start = time.time()
        while GPIO.input(pin_Echo) == 1:
            stop = time.time()
        
        check_time = stop - start
        distance = check_time * 34300 / 2
        print("Distance : %.1f cm"%distance)
        time.sleep(0.4)
        
        if distance < 10:
            GPIO.setup(pin_LED_Red, GPIO.OUT)
            GPIO.setup(pin_LED_Green, GPIO.OUT)
            GPIO.setup(pin_LED_Blue, GPIO.OUT)
            
        else:
            # turn LED on
            if count % 3 == 0:
                GPIO.output(pin_LED_Red, 1)
                time.sleep(0.5)
                GPIO.output(pin_LED_Red, 0)
                time.sleep(0.5)
                
            elif count % 3 == 1:
                GPIO.output(pin_LED_Green, 1)
                time.sleep(0.5)
                GPIO.output(pin_LED_Green, 0)
                time.sleep(0.5)
                
            elif count % 3 == 2:
                GPIO.output(pin_LED_Blue, 1)
                time.sleep(0.5)
                GPIO.output(pin_LED_Blue, 0)
                time.sleep(0.5)
            
        count += 1
        print("Blink! "+str(count))
            
        rate.sleep()

        GPIO.cleanup()      # Reset GPIO
        
    # Exception
    except rospy.ROSInterruptException:
        print("Interrupt!!")
        GPIO.setup(pin_LED_Red, GPIO.OUT)
        GPIO.setup(pin_LED_Green, GPIO.OUT)
        GPIO.setup(pin_LED_Blue, GPIO.OUT)
