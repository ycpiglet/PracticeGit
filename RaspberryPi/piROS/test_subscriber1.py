#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time
import random

# Setting pin number
pin_LED_Red = 2
pin_LED_Green = 3
pin_LED_Blue = 4
pin_Buzzer = 10

# GPIO mode setting
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM) # GPIOn Mode

# GPIO pin setting
GPIO.setup(pin_LED_Red, GPIO.OUT)
GPIO.setup(pin_LED_Green, GPIO.OUT)
GPIO.setup(pin_LED_Blue, GPIO.OUT)
GPIO.setup(pin_Buzzer, GPIO.OUT)

# Define user function
def callback(data):
        print("get message : %d"%data.data)
        if data.data % 4 == 2:
                led_on()
        elif data.data % 4 == 0:
                led_off()
        msg_list.append(data.data)
        print(msg_list)

def led_on():
        # LED
        rgb = random.randrange(2,5)
        GPIO.output(rgb, 1)
        
        p.ChangeFrequency(Frq[random.randrange(0, 8)])
        #rate.sleep()

        #p.stop()                # stop PWM
        #GPIO.cleanup()      # Reset GPIO

def led_off():
        # LED
        rgb = random.randrange(2,5)
        GPIO.output(rgb, 0)
        
# main
rospy.init_node("test_subscriber")
sub = rospy.Subscriber("topic", Int32, callback)

msg_list = list()

# Buzzer
p = GPIO.PWM(pin_Buzzer, 100)   # pin18 : PWM, 100Hz
Frq = [262, 294, 330, 349, 392, 440, 493, 523]
speed = 0.5
p.start(10)             # start PWM, Duty Cycle :10

rospy.spin()
