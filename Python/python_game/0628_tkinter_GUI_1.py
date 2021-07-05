#tkiner 모듈에 있는 모든 함수 클래스를 포함
from tkinter import *

window = Tk()

def process():
    dollar = float(e1.get()) #e1 엔트리에 있는 문자열을 읽어서 float로 변환
    e2.insert(0, str(dollar*1127))


l1 = Label(window, text='달러', font='helvetica 16 italic')
l2 = Label(window, text='원', font='helvetica 16 italic')
l1.grid(row=0, column=0) #격자 배치
l2.grid(row=1, column=0)

e1 = Entry(window, bg='yellow', fg='black')
e2 = Entry(window, background='blue', foreground='white')
e1.grid(row=0, column=1)
e2.grid(row=1, column=1)

# button = Button(window, text='클릭', command=process) #버튼 위젯을 window에 생성
# button.pack() #압축배치
b1 = Button(window, text='달러->원', command=process)
b2 = Button(window, text='원->달러')
b1.grid(row=2, column=0)
b2.grid(row=2, column=1)
b1.configure(font='helvetica 12')
b2['bg'] = 'green'

window.mainloop()