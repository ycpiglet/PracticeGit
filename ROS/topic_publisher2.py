#! /usr/bin/env python

# from typing import Counter
import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
from std_msgs.msg import Float32

def talker():
    global pub2


# pub1 = rospy.Publisher('counter1', Int32)
pub2 = rospy.Publisher('msg', String, queue_size=20)
# pub3 = rospy.Publisher('float', Float32)

r = rospy.Rate(5)
d = rospy.Duration(10, 0)
now = rospy.get_rostime()
str = "hello world&s"%rospy.get_time()
count = 0

while not rospy.is_shutdown():
    rospy.loginfo(str)
    # rospy.loginfo(count)
    rospy.loginfo("Current time %i %i", now.secs, now.nsecs)
    pub2.publish(str)
    # pub1.publish(count)
    count += 1
    
    
    rate.sleep()
    
