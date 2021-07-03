#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32

rospy.init_node('topic_publisher')

pub = rospy.Publisher('counter1', Int32) # 32bit Int

rate = rospy.Rate(2) # 2Hz

count = 0

while not rospy.is_shutdown():
    pub.publish(count)
    count += 1

    if count > 10 :  # count over 10
        new_node = str(count)
        rospy.init_node(new_node) # creat new node
        
        new_pub = rospy.Publisher(new_pub, Int32) # publisher
        new_pub.publish(count)

    rate.sleep()