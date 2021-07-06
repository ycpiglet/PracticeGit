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
        
def printMsg():
        print('Good')
        
def led_on():
        # LED
        rgb = random.randrange(2,5)
        GPIO.output(rgb, 1)
        led_off()
        
def led_off():
        # LED
        rgb = random.randrange(2,5)
        GPIO.output(rgb, 0)

def all_off():
        # LED
        GPIO.output(pin_LED_Red, 0)
        GPIO.output(pin_LED_Green, 0)
        GPIO.output(pin_LED_Blue, 0)
        
def key_input(e):
        key = e.keysym
        if key == 'space':
                print("Space")
        if key == 'Escape':
                print("Escape")
        
# main
rospy.init_node("test_subscriber")
sub = rospy.Subscriber("topic", Int32, callback)

root = tkinter.Tk()
root.title("background")
root.geometry("600x400")
canvas = tkinter.Canvas(width=300, height=150, bg='white')
canvas.pack()
label = tkinter.Label(text="NODE")
label.place(x=150, y=50)
frame = tkinter.Frame(root)
frame.pack()
Button1 = tkinter.Button(frame, text='ON', command=led_on, width=10, height=3)
Button2 = tkinter.Button(frame, text='OFF', command=all_off, width=10, height=3)
Button1.pack()
Button2.pack()

# Buzzer
p = GPIO.PWM(pin_Buzzer, 100)   # pin18 : PWM, 100Hz
Frq = [262, 294, 330, 349, 392, 440, 493, 523]
speed = 0.5
p.start(10)             # start PWM, Duty Cycle :10

root.bind('<Key>',key_input)
root.mainloop()
rospy.spin()
