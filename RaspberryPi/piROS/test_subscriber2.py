#! /usr/bin/env python3
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time
import random
import tkinter
from PIL import ImageTk, Image

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
        msg_list.append(data.data)
        print(msg_list)
        
def key_input(e):
        key = e.keysym
        if key == 'space':
                canvas.create_image(0, 0, image=img, tag='BG')
        if key == 'Escape':
                print("Escape")
                canvas.delete('BG')
        
# main
rospy.init_node("test_subscriber")
sub = rospy.Subscriber("topic", Int32, callback)

root = tkinter.Tk()
root.title("background")
root.geometry("600x400")
canvas = tkinter.Canvas(width=300, height=200)
canvas.pack()

msg_list = list()
img = ImageTk.PhotoImage(Image.open("/home/pi/catkin_ws/src/basics/scripts/background_1.jpg")) 
img2 = ImageTk.PhotoImage(Image.open("/home/pi/catkin_ws/src/basics/scripts/background_2.jpg")) 
canvas.create_image(0, 0, image=img2, tag='BG')

# Buzzer
p = GPIO.PWM(pin_Buzzer, 100)   # pin18 : PWM, 100Hz
Frq = [262, 294, 330, 349, 392, 440, 493, 523]
speed = 0.5
p.start(10)             # start PWM, Duty Cycle :10

root.bind('<Key>',key_input)
root.mainloop()
rospy.spin()
