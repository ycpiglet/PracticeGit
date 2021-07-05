import tkinter
import random

fnt1 = ('Times New Roman', 24)
fnt2 = ('Times New Roman', 50)

index = 0           # 게임 진행을 관리하는 인덱스 0: 타이틀 화면, 1: 게임중, 2: 게임 종료
timer = 0           # 타이머 변수 : 게임 종료화면에서 일정 시간 흐른 후 타이틀 화면으로 자동 전환
score = 0           # 점수 변수
bg_pos = 0          # 화면 스크롤링 변수
px, py = 240, 540   # 우주선의 위치 좌표
METEO_MAX = 30      # 유성의 개수
mx = [0]*METEO_MAX  # mx = [0, 0, 0, ..., 0]
my = [0]*METEO_MAX

key = ''            # 키 값을 대입할 전역 변수
koff = False        # 키를 눌렀다 뗐을 떼 사용하는 bool 변수

def key_down(e):
    global key, koff          # 전역변수 참조를 알림
    key = e.keysym      # key의 심볼(symbol)로 받는다
    koff = False

def key_up(e):
    global koff
    koff = True

def main():
    global index, timer, key, koff, score, bg_pos, px         # 전역변수 참조
    # canvas.delete('STATUS')     # tag='STATUS'인 object들을 삭제
    timer += 1                  # 100ms마다 main 함수를 호출하기 때문에 timer 변수는 100ms마다 1 증가
    bg_pos = (bg_pos + 1) % 640 # bg_pos = 0, 1, 2, ..., 639, 0, 1, ... 반복 증가
    canvas.delete('SCREEN')     # tag='STATUS'인 오브젝트 삭제
    canvas.create_image(240, bg_pos-320, image=img_bg, tag='SCREEN')
    canvas.create_image(240, bg_pos-320, image=img_bg, tag='SCREEN')
    # canvas.create_text(200, 30, text='index '+str(index), fill='white', font=fnt1, tag='STATUS')
    # canvas.create_text(400, 30, text='timer '+str(timer), fill='cyan', font=fnt1, tag='STATUS')

    if index == 0:      # 타이틀 화면
        canvas.create_text(240, 240, text='METEOR', fill='gold', font=fnt2, tag='SCREEN')
        canvas.create_text(240, 480, text='Press [SPACE] Key', fill='lime', font=fnt2, tag='SCREEN')
        
        if key == 'space':  # 게임 시작을 알림
            score = 0       # 점수 초기화
            px = 240        # 우주선의 위치를 x 좌표를 한 가운데로 초기화
            init_enemy()

            canvas.delete('TITLE')      # tag='TITLE'인 객체들을 삭제
            canvas.create_rectangle(0, 0, 600, 400, fill='blue', tag='GAME')
            canvas.create_text(300, 150, text='게임 중', fill='white', font=fnt2, tag='GAME')
            canvas.create_text(300, 350, text='[E] 종료', fill='lime', font=fnt2, tag='GAME')
            index = 1       # 게임 진행 status를 게임중(index=1)로 변경
            timer = 0       # timer 초기화

        if timer == 1:
            canvas.create_text(300, 150, text='타이틀 ' + str(index), fill='white', font=fnt1, tag='TITLE')
            canvas.create_text(300, 300, text='Press [SPACE] Key ' + str(timer), fill='lime', font=fnt2,
                               tag='TITLE')

    if index == 1:      # 게임 중일 때
        score += 1
        move_player()       # 우주선을 움직임
        move_enemy()        # 유성을 움직임
        # canvas.delete('GAME')  # tag='TITLE'인 객체들을 삭제
        # canvas.create_rectangle(0, 0, 600, 400, fill='maroon', tag='OVER')
        # canvas.create_text(300, 150, text='GAME OVER', fill='red', font=fnt2, tag='OVER')
        # index = 2       # 게임 종료 status로 변경
        # timer = 0       # timer 초기화
        
    if index == 2:
        move_enemy()
        canvas.create_text(240, timer*4, text='GAME OVER', fill='red', font=fnt2, tag='SCREEN')
        if timer == 60: # 게임 종료 상태에서 6초(6000ms) 후
            index = 0   # 타이틀 화면 status 변경
            timer = 0   # timer 초기화
        
    canvas.create_text(240, 30, text='SCORE'+str(score), fill='white', font=fnt1, tag='SCRREN')

    if koff == True:        # 키를 눌렀다가 뗐으면
        key = ''            # 키 심볼을 초기화
        koff = False
        
    root.after(50, main) # 50ms 후에 main 함수 다시 호출

def init_enemy():       # 유성들을 초기화
    for i in range(METEO_MAX):      # i=0,1,2,...,29
        mx[i] = random.randint(0, 480)       # random.randint는 (Start, End) 입력받은 숫자 두 개 사이의 정수를 랜덤으로 생성
        my[i] = random.randint(-640, 0)      # 화면 위쪽으로 랜덤하게 생성

def hit_check(x1, y1, x2, y2):          # 두 원의 히트 체크
    if (x1-x2)**2 + (y1-y2)**2 < 36**2:
        return True
    else:
        return False

def move_player():      # 우주선 이동, LEFT, RIGHT 키로 좌우 이동
    global px
    if key == 'Left' and px > 30:   # LEFT 키를 누르고 좌측 화면을 벗어나지 않으면
        px = px - 10
    if key == 'Right' and px < 450: # RIGGT 키를 누르고 우측 화면을 벗어나지 않으면
        px = px + 10
    canvas.create_image(px, py, image=img_player[timer%2], tag='SCREEN')

def move_enemy():       #
    global index, timer
    for i in range(METEO_MAX):      # i=0,1,2,...,29 (30개 유성에 대해서)
        my[i] = my[i] + 6 + i/5     # 빨리 내려오는 유성이 있고, 천천히 내려오는 유성이 존재
        if my[i] > 660:             # 
            mx[i] = random.randint(0, 480)  # random.randint는 (Start, End) 입력받은 숫자 두 개 사이의 정수를 랜덤으로 생성
            my[i] = random.randint(-640, 0)  # 화면 위쪽으로 랜덤하게 생성
        if index == 1 and hit_check(px, py, mx[i]. my[i]) == True :     # 게임중이고 i번째 유성과 우주선이 히트하면
            index = 2       # 게임 종료로 status 변경
            timer = 0       # timer 초기화
        canvas.create_image(mx[i], my[i], image=img_enemy, tag='SCRREN')
            
root = tkinter.Tk()
root.title('미니게임')
root.bind('<Key>', key_down)        # key, key_press, key_down 모두 동일한 의미, 키를 눌렀을 때 실행되는 함수 지정
root.bind('<KeyRelease>', key_up)

canvas = tkinter.Canvas(width=600, height=400, bg='black')
canvas.pack()

img_player = [tkinter.PhotoImage(file='starship0.png'),
               tkinter.PhotoImage(file='starship1.png')]
img_enemy = tkinter.PhotoImage(file='meteo.png')
img_bg = tkinter.PhotoImage(file='cosmo.png')

main()

root.mainloop()