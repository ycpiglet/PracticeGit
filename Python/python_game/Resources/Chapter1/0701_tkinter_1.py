import tkinter
import datetime
def time_now():
    d = datetime.datetime.now()
    t = '{0}:{1}:{2}'.format(d.hour, d.minute, d.second)