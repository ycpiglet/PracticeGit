import tkinter
import math

def hit_check_circle():
    dis = math.sqrt((x1-x2)**2 + (y1-y2)**2)        # 두 원의 중심 사이거리
    #dis = (x1-x2)**2 + (y1-y2)**2)**0.5
    if dis <= r1 + 2:       # 중심 사이의 거리가 두 원의 반지름 길이 합보다 적으면 겹친 것임
        return True
    return False


def mouse_move(e):
    global x1, y1
    x1 = e.x
    y1 = e.y
    col = 'green'
    if hit_check_circle():
        col = 'lime'
    canvas.delete('CIR1')
    canvas.create_oval(x1-r1, y1-r1, x1+r1, y1+r1, fill=col,tag='CIR1')

root = tkinter.Tk()
root.title('원을 사용한 히트 체크')
canvas = tkinter.Canvas(width=600, height=400, bg='white')
canvas.pack()
canvas.bind('<Motion>', mouse_move)     # 마우스 포인터 움직일 때 실행하는 함수
x1, y1, r1 = 50, 50, 40        # 첫 번재 사각형을 만드는 전역번수 (x1, y1) 사각형의 좌상 좌표
x2, y2, r2 = 300, 200, 80        # 첫 번재 사각형을 만드는 전역번수 (x1, y1) 사각형의 좌상 좌표
canvas.create_oval(x1-r1, y1-r1, x1+r1, y1+r1, fill='green',tag='CIR1')
canvas.create_oval(x2-r2, y2-r2, x2+r2, y2+r2, fill='orange')
root.mainloop()