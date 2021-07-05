from tkinter import *
import random # 쓰지 않으면 회색

w = 400
h = 300

colors = ['white', 'black', 'blue', 'red', 'orange', 'yellow', 'green', 'cyan'] # 색깔리스트

class Ball: #class Ball을 이용해서 Ball 객체를 여러개 생성하려고 함
    def __init__(self):
        self.x = 10 #x의 초기위치, x좌표
        self.y = 10 #y의 초기위치, y좌표
        self.dx = 2 #x방향 벡터
        self.dy = 2 #y방향 벡터
        self.color = random.choice(colors)

class MainGUI:
    def stop(self): #멤버함수
        self.isStopped = True

    def resume(self):
        self.isStopped = False
        self.animate()          # 재시작

    def add(self):              # Ball 객체 추가
        self.ballList.append(Ball())

    def subtract(self):         # Ball 객체 삭제
        self.ballList.pop()

    def faster(self):
        if self.sleep > 20:     # sleep time이 0보다 작으면 안 됨
            self.sleep -= 20

    def slower(self):
        self.sleep += 20

    def animate(self): #Ball 객체들을 animation 시킨다
        while not self.isStopped: #정지가 아니면 무한 루프
            self.canvas.after(self.sleep)   # sleep time 동안 멈췄다가 다시 동작 # after 함수는 지정한 시간동안 멈추는 함수
            self.canvas.update()            # canvas 객체들을 다시 그린다
            self.canvas.delete('ball')      # tags가 'ball'인 객체들을 모두 삭제
            for ball in self.ballList:      # self.ballList에 있는 ball들을 하나씩 꺼내서 생성
                if ball.x < 0:      # x가 벽면을 뚫지 않게
                    ball.dx = 2     # x를 양의 방향으로 변환
                elif ball.x > w:    # x가 canvas를 벗어나지 않게
                    ball.dx = -2
                if ball.y < 0:      # y가 벽면을 뚫지 않게
                    ball.dy = 2     # y를 양의 방향으로 변환
                elif ball.y > h:    # y가 canvas를 벗어나지 않게
                    ball.dy = -2
                ball.x += ball.dx   # dx 방향으로 이동
                ball.y += ball.dy   # dy 방향으로 이동
                self.canvas.create_oval(ball.x-5, ball.y-5, ball.x+5, ball.y+5, fill=ball.color, tag='ball')

    def __init__(self): #생성자
        window = Tk()
        window.title('공 튀기기')
        self.canvas = Canvas(window, width = w, height = h)
        self.canvas.pack()  #압축배치자
        self.ballList = []      #Ball 객체를 담는 리스트
        self.isStopped = False  #정지/재시작을 관리하는 변수
        self.sleep = 100        #sleep time을 100ms로 설정, 빠르게/느리게 관리하는 변수
        frame = Frame(window)   #container 위젯
        frame.pack()
        Button(frame, text='정지', command=self.stop).pack(side=LEFT)
        Button(frame, text='재시작', command=self.resume).pack(side=LEFT)
        Button(frame, text='+', command=self.add).pack(side=LEFT)
        Button(frame, text='-', command=self.subtract).pack(side=LEFT)
        Button(frame, text='빠르게', command=self.faster).pack(side=LEFT)
        Button(frame, text='느리게', command=self.slower).pack(side=LEFT)
        self.animate()
        window.mainloop()

MainGUI() #class MainGUI의 객체를 생성하기 위해서 생성자를 호출