from tkinter import *
#객체지향 언어 class

w = 400 # 전역변수 : 프로그램 전체에서 어디에서든 접근 가능
h = 400

class Ball:
    def __init__(self): #Ball 클래스 생성자
        self.x = 10 # 멤버변수
        self.y = 10

class MainGUI: #class(키워드), MainGUI(클래스 이름)
    def up(self):
        if self.ball.y > 5 : # if 조건문
            self.ball.y -= 5 # y값을 5만큼 감소, 즉 위로 5 이동
            self.canvas.delete('ball') #Canvas에 그린 객체 중에서 tags가 'ball'인 객체를 지운다
            self.canvas.create_oval(self.ball.x - 5, self.ball.y - 5, self.ball.x + 5, self.ball.y + 5,
                                    fill='red', tags='ball')

    def down(self):
        #pass # 코드없는 문장, 아무것도 없으면 Error가 발생하기 때문에 써주는 것
        if self.ball.y < h-5 : # if 조건문
            self.ball.y += 5 # y값을 5만큼 감소, 즉 위로 5 이동
            self.canvas.delete('ball') #Canvas에 그린 객체 중에서 tags가 'ball'인 객체를 지운다
            self.canvas.create_oval(self.ball.x - 5, self.ball.y - 5, self.ball.x + 5, self.ball.y + 5,
                                    fill='red', tags='ball')

    def left(self):
        if self.ball.x > 5:  # if 조건문
            self.ball.x -= 5  # y값을 5만큼 감소, 즉 위로 5 이동
            self.canvas.delete('ball')  # Canvas에 그린 객체 중에서 tags가 'ball'인 객체를 지운다
            self.canvas.create_oval(self.ball.x - 5, self.ball.y - 5, self.ball.x + 5, self.ball.y + 5,
                                    fill='red', tags='ball')
    def right(self):
        if self.ball.x < w- 5:  # if 조건문
            self.ball.x += 5  # y값을 5만큼 감소, 즉 위로 5 이동
            self.canvas.delete('ball')  # Canvas에 그린 객체 중에서 tags가 'ball'인 객체를 지운다
            self.canvas.create_oval(self.ball.x - 5, self.ball.y - 5, self.ball.x + 5, self.ball.y + 5,
                                    fill='red', tags='ball')

    def __init__(self): #생성자
        window = Tk()
        window.title('공 옮기기')
        self.canvas = Canvas(window, width=w, height=h, bg='white') #전역변수 참조
        #self 붙이면 멤버변수(다른 곳에서 활용 가능),  안 붙이면 지역변수(생성자 안에서만 사용 가능)
        self.canvas.pack() #압축배치
        self.ball = Ball() # Ball 클래스 객체 생성
        self.canvas.create_oval(self.ball.x-5, self.ball.y-5, self.ball.x+5, self.ball.y+5,
                                fill='red', tags='ball') #두 점 (x1, y1), (x2, y2)을 갖는 직사각형에 꽉차는 타원(oval) 그림을 만든다
        #버튼 4개를 감싸는 contatiner 위젯 frame 생성
        frame = Frame(window)
        frame.pack()
        Button(frame, text='상', command=self.up).pack(side=LEFT)
        Button(frame, text='하', command=self.down).pack(side=LEFT)
        Button(frame, text='좌', command=self.left).pack(side=LEFT)
        Button(frame, text='우', command=self.right).pack(side=LEFT)
        window.mainloop()

MainGUI() # class 객체 생성 (생성자 호출)