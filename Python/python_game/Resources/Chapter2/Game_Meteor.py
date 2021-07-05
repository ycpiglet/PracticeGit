import tkinter
import random
fnt1 = ('Times New Roman',24)
fnt2 = ('Times New Roman',50)
index = 0       #게임 진행관리하는 인덱스 0:타이틀화면 1:게임중 2:종료화면
timer = 0       #타이머 변수 (게임종료에서 일정 시간이 흐른후 타이틀화면으로 자동 전환)
score = 0       #점수 변수
bg_pos = 0      #화면 스크롤링 변수
px, py = 240,540    #우주선의 위치 좌표
METEO_MAX = 30  #유성의 개수
mx = [0]*METEO_MAX  #mx=[0,0,0,0...,0]
my = [0]*METEO_MAX

key = ''        #키 값을 대입할 전역변수
koff = False    #키를 눌렀다 뗏을 때 사용하는 bool 변수
def key_down(e):    #키를 눌렀을 때 실행되는 함수
    global key,koff  #전역변수 참조를 알림
    key = e.keysym
    koff = False
def key_up(e):  #키를 뗏을 때 실행되는 함수
    global koff
    koff = True

def main():
    global key, koff, index, timer, score, bg_pos, px #전역변수 참조
    timer += 1  #100ms 마다 main 함수를 호출하기 때문에 timer 변수는 100ms 마다 1증가함
    bg_pos = (bg_pos + 1) % 480 #bg_pos = 0,1,2...639, 0,1, ..반복 증가
    canvas.delete('SCREEN')  # tag='STATUS' 인 오브젝트들을 삭제
    canvas.create_image(bg_pos-240,320,image=img_bg,tag='SCREEN')
    canvas.create_image(bg_pos+240,320,image=img_bg,tag='SCREEN')
    if index == 0:  #타이틀 화면이면
        canvas.create_text(240, 240, text='도둑고양이', fill='gold', font=fnt2, tag='SCREEN')
        canvas.create_text(240, 480, text='Press [SPACE] Key', fill='lime', font=fnt1, tag='SCREEN')
        if key == 'space':  #게임 시작을 알림
            score = 0   #점수 초기화
            px = 240    #우주선의 위치를 x좌표를 한가운데로 초기화
            init_enemy()    #유성들을 초기화
            index = 1   #게임 진행 status 를 게임중(index = 1)로 변경

    if index == 1:  #게임중일 때
        score = score + 1
        move_player()   #우주선을 움직임
        move_enemy()    #유성을 움직임

    if index == 2:  #게임 종료상태일때
        move_enemy()
        canvas.create_text(240,timer*4,text='GAME OVER', fill='red',font=fnt2,tag='SCREEN')
        if timer == 60:  #게임 종료 상태에서 3초 후
            index = 0   #타이틀 화면 status 변경
            timer = 0   #timer 초기화

    canvas.create_text(240,30,text='SCORE' + str(score), fill='white', font=fnt1, tag='SCREEN')
    if koff == True:    #키를 눌렀다가 뗏으면
        key = ''        #키 심볼을 초기화
        koff = False

    root.after(50,main)    #50ms 후에 main 함수 다시 호출

def hit_check(x1,y1,x2,y2): #두 원의 히트 체크
    if (x1-x2)**2 + (y1-y2)**2 < 36**2:
        return True
    else:
        return False

def init_enemy():   #유성들을 초기화
    for i in range(METEO_MAX):  #i=0,1,2...29
        mx[i] = random.randint(0,480)   #random.randint 함수 [Start,End] 인자를 주면 그 사이의 정수 랜덤 생성
        my[i] = random.randint(-640,0)  #화면 위쪽으로 랜덤하게 생성

def move_enemy():   #유성을 이동
    global index, timer
    for i in range(METEO_MAX):  #i=0,1,2,..29 (30개 유성에 대해서)
        my[i] = my[i] + 6 + i/5 #빨리 내려오는 유성이 있고 천천히 내려오는 유성이 존재
        if my[i] > 660: #유성이 화면 아래로 벗어나면 다시 생성
            mx[i] = random.randint(0, 480)  # random.randint 함수 [Start,End] 인자를 주면 그 사이의 정수 랜덤 생성
            my[i] = random.randint(-640, 0)  # 화면 위쪽으로 랜덤하게 생성
        if index == 1 and hit_check(px,py,mx[i],my[i]) == True: #게임중이고 i번째 유성과 우주선이 히트하면
            index = 2   #게임 종료로 status 변경
            timer = 0   #timer 초기화
        canvas.create_image(mx[i],my[i],image=img_enemy,tag='SCREEN')

def move_player():  #우주선 이동 #LEFT, RIGHT 키로 우주선을 좌우 이동
    global px   #전역변수 우주선 x좌표
    if key == 'Left' and px > 30:   #LEFT 키를 누르고 좌측 화면을 벗어나지 않으면
        px = px - 10
    if key == 'Right' and px < 450:   #RIGHT 키를 누르고 우측 화면을 벗어나지 않으면
        px = px + 10
    canvas.create_image(px,py,image=img_player[timer % 2],tag='SCREEN')

root = tkinter.Tk()
root.title('Mini Game')
root.bind('<Key>',key_down) #키를 눌렀을 때 실행되는 key_down 함수 지정
root.bind('<KeyRelease>',key_up) #키를 뗏을 때 실행되는 key_up 함수 지정
canvas = tkinter.Canvas(width=480,height=640)
canvas.pack()
img_player = [tkinter.PhotoImage(file='dora0.png'),
              tkinter.PhotoImage(file='dora1.png')] #우주선 이미지 리스트
img_enemy = tkinter.PhotoImage(file='fun.png')        #유성 이미지
img_bg = tkinter.PhotoImage(file='building.png')           #배경 이미지
main()
root.mainloop()





