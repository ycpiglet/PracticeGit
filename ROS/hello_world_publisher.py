<<<<<<< HEAD
#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('hello_pub', String, queue_size=10)

rospy.init_node('hello_world_publisher', anonymous=True)

r = rospy.Rate(10) # 10Hz

while not rospy.is_shutdown():
    str = "hello world%s"%rospy.get_time()
    rospy.loginfo(str)
    pub.publish(str)
    r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass
=======
#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('hello_pub', String, queue_size=10)

rospy.init_node('hello_world_publisher', anonymous=True)

r = rospy.Rate(10) # 10Hz

while not rospy.is_shutdown():
    str = "hello world%s"%rospy.get_time()
    rospy.loginfo(str)
    pub.publish(str)
    r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass
>>>>>>> 30cc49dcdebc0338b8926ba1ca9da7a039cedc78
