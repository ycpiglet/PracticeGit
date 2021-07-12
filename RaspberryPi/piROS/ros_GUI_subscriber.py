#! /usr/bin/env python3
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time
#import cv2

# Define user function
def callback(data):
        #msg_list.append(data.data)
        #print(msg_list)
        print(data.data)
        if data.data > 100:
                Pi(data.data)
                
def callback_String(data):
        
        
        if data.data == 'buzzer':
                print(data.data) 
                p.start(10)             # start PWM, Duty Cycle :10
                p.ChangeFrequency(Frq[4])
        
        elif data.data == 'led':
                print(data.data)
                GPIO.output(pin_LED_Red, 1)
                time.sleep(0.5)
                GPIO.output(pin_LED_Red, 0)
                time.sleep(0.5)    
        else:
                print(data.data + " is not option")
                p.stop()                # stop PWM
                
def Pi(count):
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
                




#main
button = 0
rospy.init_node("RapberryPi4")
msg_list = list()
# Setting pin number
pin_LED_Red = 2
pin_LED_Green = 3
pin_LED_Blue = 4
pin_Trig = 27
pin_Echo = 17
pin_Switch = 22
pin_Buzzer = 10
pin_GND = 6

# GPIO mode setting
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM) # GPIOn Mode

# GPIO pin setting
GPIO.setup(pin_LED_Red, GPIO.OUT)
GPIO.setup(pin_LED_Green, GPIO.OUT)
GPIO.setup(pin_LED_Blue, GPIO.OUT)
GPIO.setup(pin_Buzzer, GPIO.OUT)
GPIO.setup(pin_Trig, GPIO.OUT)
GPIO.setup(pin_Echo, GPIO.IN)
GPIO.setup(pin_Switch, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

p = GPIO.PWM(pin_Buzzer, 100)   # pin18 : PWM, 100Hz
Frq = [262, 294, 330, 349, 392, 440, 493, 523]
speed = 0.5


try:
        sub1 = rospy.Subscriber("counter", Int32, callback)
        sub2 = rospy.Subscriber("message", String, callback_String)
        
        rospy.spin()
        
except rospy.ROSInterruptException:
        print("Interrupt!!")
