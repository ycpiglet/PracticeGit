import tkinter

def hit_check_rect():
    dx = abs((x1+w1/2) - (x2+w2/2))
    dy = abs((y2+h1/2) - (y2+h2/2))
    if dx <= w1/2 + w2/2 and dy <= h1/2 + h2/2:
        return True
    return False


def mouse_move(e):
    global x1, y1
    x1 = e.x - w1/2
    y1 = e.y - h1/2
    col = 'blue'
    if hit_check_rect():
        col = 'cyan'
    canvas.delete('RECT1')
    canvas.create_rectangle(x1, y1,  x1+w1, y1+h1, fill=col, tag='RECT1')

root = tkinter.Tk()
root.title('사각형을 사용한 히트 체크')
canvas = tkinter.Canvas(width=600, height=400, bg='white')
canvas.pack()
canvas.bind('<Motion>', mouse_move)     # 마우스 포인터 움직일 때 실행하는 함수
x1, y1, w1, h1 = 50, 50, 120, 60        # 첫 번재 사각형을 만드는 전역번수 (x1, y1) 사각형의 좌상 좌표
x2, y2, w2, h2 = 300, 100, 120, 160        # 첫 번재 사각형을 만드는 전역번수 (x1, y1) 사각형의 좌상 좌표
canvas.create_rectangle(x1, y1, x1+w1, y1+h1, fill='blue', tag='RECT1')     # 파란색 사각형 tag 지정
canvas.create_rectangle(x2, y2, x2+w2, y2+h2, fill='red')
root.mainloop()