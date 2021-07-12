#! /usr/bin/env python3
#from std_msgs.msg import Int32
#from std_msgs.msg import String
#import RPi.GPIO as GPIO
import time
import random
import tkinter
from tkinter.constants import S
import tkinter.font
#from PIL import ImageTk, Image

class ROS_GUI():
    # Interrupt
    def key_input(self, e):
        key = e.keysym
        if key == 'space':
            print("Pressed Space")
        if key == 'Escape':
            print("Pressed Escape")

    # RaspberryPi
    def led_on(self):
        print('LED ON')

    def led_off(self):
        print('LED OFF')

    def buzzer_on(self):
        print('Buzzer ON')

    def buzzer_off(self):
        print('Buzzer OFF')

    # ROS
    def initPublisher(self):
        print('Initiate Publisher')

    def termPublisher(self):
        print('Terminate Publisher')

    def initSubscriber(self):
        print('Initiate Subscriber')

    def termSubscriber(self):
        print('Terminate Publisher')

    # GUI Setup
    def setupWindow(self):
        self.window = tkinter.Tk()
        self.window.title("ROS GUI")
        self.window.geometry("600x600")
        self.window.configure(bg='skyblue')
        self.window.resizable(False, False)

    def setupCanvas(self):
        self.canvas = tkinter.Canvas(width=600, height=200, bg='white')
        self.canvas.pack()

    def setupFont(self):
        self.fontStyle1 = tkinter.font.Font(self.window, size=24, weight='bold', family='Consoles')
        self.fontStyle2 = tkinter.font.Font(self.window, size=12, weight='bold', family='Consoles')
        self.fontStyle3 = tkinter.font.Font(self.window, size=12, weight='normal', family='Consoles')

    def setupLabel(self):
        self.label = tkinter.Label(text="ROS GUI for Topic", font=self.fontStyle1)
        self.label.place(x=150, y=10)

    def setupFrame(self):
        self.frame1 = tkinter.Frame(self.window)
        self.frame2 = tkinter.Frame(self.window)
        self.frame3 = tkinter.Frame(self.window)
        self.frame1.pack()
        self.frame2.pack()
        self.frame3.pack()

    def setupText(self):
        self.text = tkinter.Text(self.frame2, width=50, height=4)
        self.text.configure(font=self.fontStyle3)
        self.text.pack()

    def setupButton(self):
        # frame1
        self.button1 = tkinter.Button(self.frame1, text='LED ON', command=self.led_on, width=14, height=4, font=self.fontStyle2)
        self.button2 = tkinter.Button(self.frame1, text='LED OFF', command=self.led_off, width=14, height=4, font=self.fontStyle2)
        self.button3 = tkinter.Button(self.frame1, text='Buzzer ON', command=self.buzzer_on, width=14, height=4, font=self.fontStyle2)
        self.button4 = tkinter.Button(self.frame1, text='Buzzer OFF', command=self.buzzer_off, width=14, height=4, font=self.fontStyle2)
        self.button1.pack(side='left')
        self.button2.pack(side='left')
        self.button3.pack(side='left')
        self.button4.pack(side='left')

        # frame2
        self.btnRead = tkinter.Button(self.frame2, width=10, height=2, text="Read", command=self.getTextInput, font=self.fontStyle2)
        self.btnErase = tkinter.Button(self.frame2, width=10, height=2, text="Erase", command=self.eraseTextInput, font=self.fontStyle2)
        self.btnRead.pack(side='left')
        self.btnErase.pack(side='left')

        # frame3
        self.btnInit = tkinter.Button(self.frame3, width=10, height=3, text='Initiate Publisher', command=self.initPublisher, font=self.fontStyle2)
        self.btnTerm = tkinter.Button(self.frame3, width=10, height=3, text='Terminate Publisher', command=self.termPublisher, font=self.fontStyle2)
        self.btnInit.pack(side='left')
        self.btnTerm.pack(side='left')

    def getTextInput(self):
        self.input = self.text.get("1.0", 'end-1c')
        print(self.input)

        if self.input == '13':
            print('Good')

    def eraseTextInput(self):
        self.text.delete("1.0", 'end-1c')

    # Class Constructor
    def __init__(self):
        # Setup GUI
        self.setupWindow()
        self.setupCanvas()
        self.setupFrame()
        self.setupFont()
        self.setupLabel()
        self.setupText()
        self.setupButton()

        self.window.bind('<Key>',self.key_input)
        self.window.mainloop()

# main
gui = ROS_GUI()