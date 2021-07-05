import tkinter
import math

root = tkinter.Tk()
root.title('삼각함수를 활용한 도형 그리기')
canvas = tkinter.Canvas(width=600, height=600, bg='black')
canvas.pack()       # 압축배치

COL = ['greenyellow', 'limegreen', 'aquamarine', 'cyan', 'deepskyblue',
       'blue', 'blueviolet', 'violet']

for d in range(360):      # range는 파이썬 내장 함수 : 수열을 생성 (start, stop, step), d = 0, 10, 20, 30, ..., 80
    a = math.radians(d)         # 각도를 라디안으로 변경
    x = 250*math.cos(a)         # 삼각함수 cos은 직각삼각형의 밑변의 길이 = x (빗면의 길이가 1일 때)
    y = 250*math.sin(a)         # 삼각함수 sin은 직각삼각형의 높이의 길이 = y (빗면의 길이가 1일 때)
    canvas.create_line(300, 300, 300+x, 300+y, fill=COL[d%8], width=2)

root.mainloop()