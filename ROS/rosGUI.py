#! /usr/bin/env python3
#from std_msgs.msg import Int32
#from std_msgs.msg import String
#import RPi.GPIO as GPIO
import time
import random
import tkinter
import tkinter.font
#from PIL import ImageTk, Image

def key_input(e):
    key = e.keysym
    if key == 'space':
        print("Pressed Space")
    if key == 'Escape':
        print("Pressed Escape")

def led_on():
    print('LED ON')

def led_off():
    print('LED OFF')

def buzzer_on():
    print('Buzzer ON')

def buzzer_off():
    print('Buzzer OFF')

root = tkinter.Tk()
root.title("ROS control GUI")
root.geometry("600x400")
root.resizable(False, False)

canvas = tkinter.Canvas(width=600, height=200, bg='white')
canvas.pack()
fontsytle = tkinter.font.Font(root, size=24, weight='bold', family='Consoles')
label = tkinter.Label(text="ROS Topic", font=fontsytle)
label.place(x=150, y=50)
frame = tkinter.Frame(root)
frame.pack()
button1 = tkinter.Button(frame, text='LED ON', command=led_on, width=20, height=5)
button2 = tkinter.Button(frame, text='LED OFF', command=led_off, width=20, height=5)
button3 = tkinter.Button(frame, text='Buzzer ON', command=buzzer_on, width=20, height=5)
button4 = tkinter.Button(frame, text='Buzzer OFF', command=buzzer_off, width=20, height=5)
button1.pack(side='left')
button2.pack(side='left')
button3.pack(side='left')
button4.pack(side='left')

root.bind('<Key>',key_input)
root.mainloop()