#! /usr/bin/env python
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time

# Define user function
def button_callback(pin_Switch):
        global button
        print("Button pushed!!")
        button += 1

# ROS setting
rospy.init_node("topic_led")
pub = rospy.Publisher('counter', Int32, queue_size=10)
rate = rospy.Rate(2)

# main
count = 0
button = 0

# while working rightly
while not rospy.is_shutdown():
    try:
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
        
        # Check switch
        GPIO.add_event_detect(pin_Switch, GPIO.RISING, callback=button_callback)
        
        # Buzzer
        p = GPIO.PWM(pin_Buzzer, 100)   # pin18 : PWM, 100Hz
        Frq = [262, 294, 330, 349, 392, 440, 493, 523]
        speed = 0.5
        p.start(10)             # start PWM, Duty Cycle :10
        if button % 2 == 0:
                p.ChangeFrequency(Frq[0])
        else:
                p.ChangeFrequency(Frq[4])
        
        # Check ultra sonic
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
        
        if distance < 10:
            p.ChangeFrequency(Frq[7])    
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
        
        time.sleep(0.4)
            
        count += 1
        
        print("Blink! "+str(count))
        print("Distance : %.1f cm"%distance)
        
        # publishing message
        pub.publish(count)
        pub.publish(distance)
            
        rate.sleep()
        
        p.stop()                # stop PWM
        GPIO.cleanup()      # Reset GPIO
        
    # Exception
    except rospy.ROSInterruptException:
        p.ChangeFrequency(Frq[1]) 
        print("Interrupt!!")
        GPIO.setup(pin_LED_Red, GPIO.OUT)
        GPIO.setup(pin_LED_Green, GPIO.OUT)
        GPIO.setup(pin_LED_Blue, GPIO.OUT)
