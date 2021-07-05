import math
import tkinter

def trigo():

    d = eval(entry.get())      # Degree, Entry는 문자열로 받음, eval로 실수로 변환(float 함수 써도 동일)
    a = math.radians(d)        # Degree -> Radian
    s = math.sin(a)
    c = math.cos(a)
    t = math.tan(a)

    label_s['text'] = 'sin {0:.5f}'.format(s)
    label_c['text'] = 'cos {0:.5f}'.format(c)
    label_t['text'] = 'tan '+str(t)

    # print('sin {0:.5f}'.format(s))
    # print('cos {}'.format(c))
    # print('tan '+str(t))

root = tkinter.Tk()
root.geometry('300x200')
root.title('삼각함수 값')

entry = tkinter.Entry(width=10)         # 한 줄짜리 입력 창
entry.place(x=20, y=20)     # 절대배치자 (x, y) 좌표 지정
button = tkinter.Button(text='계산', command=trigo)
button.place(x=110, y=20)
label_s = tkinter.Label(text='sin(x)')
label_s.place(x=20, y=60)
label_c = tkinter.Label(text='cos(x)')
label_c.place(x=20, y=100)
label_t = tkinter.Label(text='tan(x)')
label_t.place(x=20, y=140)

root.mainloop()