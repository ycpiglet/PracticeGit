import tkinter
import math

root = tkinter.Tk()
root.title('삼각함수를 활용한 선 그리기')
canvas = tkinter.Canvas(width=400, height=400, bg='white')
canvas.pack()       # 압축배치

for d in range(0, 90, 10):      # range는 파이썬 내장 함수 : 수열을 생성 (start, stop, step), d = 0, 10, 20, 30, ..., 80
    a = math.radians(d)         # 각도를 라디안으로 변경
    x = 300*math.cos(a)         # 삼각함수 cos은 직각삼각형의 밑변의 길이 = x (빗면의 길이가 1일 때)
    y = 300*math.sin(a)         # 삼각함수 sin은 직각삼각형의 높이의 길이 = y (빗면의 길이가 1일 때)
    canvas.create_line(0, 10, x, y+10, fill='blue')

root.mainloop()