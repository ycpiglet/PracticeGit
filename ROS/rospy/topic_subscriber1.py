#! /usr/bin/env python

import rospy
from std_msgs.msg import Int32
from std_msgs.msg import String
from std_msgs.msg import Float32

def callback(data):
    split = data,data.split()
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    print data.data

    if split[0] == "init":
        rospy.init_node(split[1], anonymous=True)
        new_pub = rospy.Publisher('new_publisher'+split[1], String, queue_size=20)
        rospy.loginfo(new_pub)
        new_pub.publish("Great!!")


def listener():
    rospy.init_node('hello_world_subscriber', anonymous=True)
    rospy.Subscriber("hello_pub", String, callback)


rospy.init_node('topic_subscriber1')

sub1 = rospy.Subscriber('counter', Int32, callback)




rospy.spin()

if __name__ == '__main__':
    listener()