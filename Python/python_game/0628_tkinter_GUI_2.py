from tkinter import *

window = Tk()

# 절대배치
l1 = Label(window, text='김영식', bg='red', fg='white', font='helvetica 16 italic')
l2 = Label(window, text='이재영', bg='green', fg='white', font='helvetica 16 italic')
l3 = Label(window, text='장지웅', bg='blue', fg='white', font='helvetica 16 italic')

# 윈도우 좌표계
# 원점위치 (좌측 상단)
l1.place(x=0, y=0) # 절대배치
l2.place(x=100, y=30)
l3.place(x=200, y=60)

window.mainloop()