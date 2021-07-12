#! /usr/bin/env python3
from std_msgs.msg import Int32
from std_msgs.msg import String
#import RPi.GPIO as GPIO
import rospy
from multiprocessing import Queue, Process
import time
import random
import tkinter
from tkinter.constants import S
import tkinter.font
from PIL import ImageTk, Image

def warning():
    global loop
    print("warning!!")
    # while loop:
    #     print("warning!!")
    #     time.sleep(1)

class RaspberryPi4():
    def Sonar(self):
        pass
        try:
            while not rospy.is_shutdown():
                self.count += 1
                self.pub1.publish(self.count)
                # print(self.count)
        except rospy.ROSException:
            pass
            # print("finisehd")
        # while not rospy.is_shutdown():
        #    self.count += 1
        #    self.pub1.publish(self.count)

    def __init__(self):
        self.pub1 = rospy.Publisher('counter', Int32, queue_size=10)
        self.pub2 = rospy.Publisher("message", String, queue_size=10)
        self.rate = rospy.Rate(2)
        self.count = 0
        # self.topic.pub1 = 0
        # self.topic.rate = 0
        pass

class ROS_topic():
    def __init__(self):
        rospy.init_node("PC_GUI")
        
        print(" Start Node ")

    def sensing(self):
        pass

class ROS_GUI():
    # Interrupt
    def key_input(self, event):
        key = event.keysym
        if key == 'space':
            topic.a = 3
            print(topic.a)
            print("Pressed Space")
        if key == 'Escape':
            print("Pressed Escape")

    

    def destroy(self, event):
        self.window.destroy()
    
    # RaspberryPi
    def led_on(self):
        print('LED ON')
        self.button2['state'] = 'active'

    def led_off(self):
        print('LED OFF')
        self.button2['state'] = 'disabled'

    def buzzer_on(self):
        print('Buzzer ON')
        self.button4['state'] = 'active'
        self.button3['bg'] = 'white'
        
    def buzzer_off(self):
        print('Buzzer OFF')
        self.button4['state'] = 'disabled'

    def pushed_buzzer_on(self):
        self.buzzer_on()

    def pushed_buzzer_off(self):
        self.buzzer_off()

    def pushed_led_on(self):
        self.led_on()

    def pushed_led_off(self):
        self.led_off()

    def pushed_btnInitPub(self):
        global loop
        loop = True
        self.label_pub = tkinter.Label(text="Publisher", font=self.fontStyle3, bg='white')
        self.label_pub.place(x=300, y=450)
        

        self.btnInitPub['state'] = 'disabled'
        self.btnTermPub['state'] = 'active'
        self.initPublisher()

    def pushed_btnTermPub(self):
        self.label_pub.destroy()
        # self.label_pub['text'] = ''
        self.btnInitPub['state'] = 'active'
        self.btnTermPub['state'] = 'disabled'
        self.termPublisher()

    # ROS
    def initPublisher(self):
        global loop
        # print('Initiate Publisher')
        
        if loop == True:
            pi.Sonar()
            self.window.after(100, self.initPublisher)
        # if loop == False:
            # warning
        
        if __name__ == '__main__':
            p1 = Process(target=pi.Sonar)
            #p2 = Process(target=warning)
            p1.start()
            #p2.start()
            #p1.join()
            #p2.join()       
        # while not rospy.is_shoutdown():
        #   topic.pub1 = rospy.Publisher('counter', Int32, queue_size=10)
        #   topic.rate = rospy.Rate(2)
        #   topic.pub1.publish()

    def termPublisher(self):
        global loop
        pi.pub1.unregister()
        print('Terminate Publisher')
        
        loop = False

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
        self.label = tkinter.Label(text="ROS GUI for Topic", font=self.fontStyle1, bg='white')
        self.label.place(x=150, y=550)
        self.label2 = tkinter.Label(text="Current Topic : ", font=self.fontStyle3, bg='white')
        self.label2.place(x=150, y=450)

    def setupFrame(self):
        self.frame1 = tkinter.Frame(self.window)
        self.frame2 = tkinter.Frame(self.window)
        self.frame3 = tkinter.Frame(self.window)
        self.frame4 = tkinter.Frame(self.window)
        self.frame1.pack()
        self.frame2.pack()
        self.frame3.pack()
        self.frame4.pack()

    def setupText(self):
        self.text = tkinter.Text(self.canvas, width=52, height=7)
        self.text.configure(font=self.fontStyle3)
        self.text.pack()

    def setupButton(self):
        # frame1
        self.button1 = tkinter.Button(self.frame1, text='LED ON', command=self.pushed_led_on, width=14, height=4, font=self.fontStyle2)
        self.button2 = tkinter.Button(self.frame1, text='LED OFF', command=self.pushed_led_off, width=14, height=4, font=self.fontStyle2, state='disabled')
        self.button3 = tkinter.Button(self.frame1, text='Buzzer ON', command=self.pushed_buzzer_on, width=14, height=4, font=self.fontStyle2)
        self.button4 = tkinter.Button(self.frame1, text='Buzzer OFF', command=self.pushed_buzzer_off, width=14, height=4, font=self.fontStyle2, state='disabled')
        self.button1.pack(side='left')
        self.button2.pack(side='left')
        self.button3.pack(side='left')
        self.button4.pack(side='left')

        # frame2
        self.btnRead = tkinter.Button(self.canvas, width=20, height=2, text="Read", command=self.getTextInput, font=self.fontStyle2)
        self.btnErase = tkinter.Button(self.canvas, width=20, height=2, text="Erase", command=self.eraseTextInput, font=self.fontStyle2, state='disabled')
        self.btnRead.pack(side='left')
        self.btnErase.pack(side='left')
        
        # frame3
        self.btnInitPub = tkinter.Button(self.frame3, width=20, height=3, text='Initiate Publisher', command=self.pushed_btnInitPub, font=self.fontStyle2)
        self.btnTermPub = tkinter.Button(self.frame3, width=20, height=3, text='Terminate Publisher', command=self.pushed_btnTermPub, font=self.fontStyle2, state='disabled')
        self.btnInitPub.pack(side='left')
        self.btnTermPub.pack(side='left')

    def getTextInput(self):
        self.input = self.text.get("1.0", 'end-1c')
        
        if self.input == '':
            self.btnErase['state'] = 'disabled'

        else:
            self.btnErase['state'] = 'active'
            pi.pub2.publish(self.input)

    def eraseTextInput(self):
        self.text.delete("1.0", 'end-1c')
        self.btnErase['state'] = 'disabled'

    # main
    def main(self):
        # self.window.after(300,self.main)
        print(2)
        time.sleep(1)

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
        # Flag
        self.flag_buzzer = False
        self.flag_led = False
        self.flag_publisher = False
        self.flag_subscriber = False

        self.window.bind('<Key>',self.key_input)
        self.window.bind('<Control-c>', self.destroy)
        self.window.mainloop()


rospy.init_node("PC_GUI")

# main
loop = False
pi = RaspberryPi4()
topic = ROS_topic()
gui = ROS_GUI()
