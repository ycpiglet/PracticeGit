import tkinter

x = 0           # 전역변수
ani = 0

def animation():
    global x, ani           # 전역변수를 참조한다.
    x = (x + 1)%480
    # x = x + 1
    #if x == 480:
    #    x = 0
    canvas.delete('BG')         # tag가 'BG'인 오브젝트를 생성
    canvas.create_image(x-240, 150, image=img_bg, tag='BG')
    canvas.create_image(x+240, 150, image=img_bg, tag='BG')
    ani = (ani + 1)%4
    canvas.create_image(360-x, 200, image=img_dog[ani], tag='BG')
    root.after(100, animation)

root = tkinter.Tk()
root.title('Canvas에 화면 그리기')
canvas = tkinter.Canvas(width=480, height=300)
canvas.pack()
img_bg = tkinter.PhotoImage(file='park.png')
img_dog = [ tkinter.PhotoImage(file='dog0.png'),
            tkinter.PhotoImage(file='dog1.png'),
            tkinter.PhotoImage(file='dog2.png'),
            tkinter.PhotoImage(file='dog3.png')]
animation()
# canvas.create_image(240, 150, image=img_bg)         # 캔버스의 정가운데 (240, 150)에 이미지를 위치시킨다
root.mainloop()