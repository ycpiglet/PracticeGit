import re
import tkinter

def mouse_click(e):
    px = e.x   # 마우스 포인터 x 좌표
    py = e.y   # 마우스 포인터 x 좌표
    print('마우스 포인터 좌표 : ({}, {})'.format(px, py))
    mx = px // 48       # 정수 나눗셈 (소숫점이 없음)
    my = py // 48
    if 0 <= mx <= 6 and 0 <= my <= 4:
        n = map_data[mx][my]
        print("여기에 있는 맵 칩은 " + CHIP_NAME[n])

root = tkinter.Tk()
root.title('맵 데이터')
canvas = tkinter.Canvas(width=336, height=240)
canvas.pack()
canvas.bind('<Button>', mouse_click)            # 마우스 왼쪽 버튼 클릭 함수 지정
CHIP_NAME = ["풀", "꽃", "숲", "바다"]
img = [ tkinter.PhotoImage(file='chip0.png'),       # 풀
        tkinter.PhotoImage(file='chip1.png'),       # 꽃
        tkinter.PhotoImage(file='chip2.png'),       # 나무
        tkinter.PhotoImage(file='chip3.png')]       # 바다
map_data = [
    [0,1,0,2,2,2,2],
    [3,0,0,0,2,2,2],
    [3,0,0,1,0,0,0],
    [3,3,0,0,0,0,1],
    [3,3,3,3,3,0,0],
]
for y in range(5):
    for x in range(7):
        n = map_data[y][x]
        canvas.create_image(x*48+24, y*48+24, image=img[n])

root.mainloop()