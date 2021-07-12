import tkinter      #tkinter 모듈 임포트
import random       #random 모듈 임포트

#키입력
key = ''            #key symbol 전역변수
koff = False        #키를 눌렀다 뗐을 때 True가 되는 bool 변수
def key_down(e):    #키를 눌렀을 때 실행되는 함수
    global key, koff    #전역변수 참조
    key = e.keysym  #e 이벤트 인자로부터 key symbol 추출해서 key에 대입한다.
    koff = False    #키가 눌리면 koff = False

def key_up(e):      #키를 눌렀다 뗐을 때 실행되는 함수
    #global koff     #전역변수 참조
    #koff = True     #눌렀따 뗐을 때 설정
    global key      #Windows
    key = ''        #Windows key symbol 초기화

DIR_UP = 0          #캐릭터 방향 정의 변수 (위쪽)
DIR_DOWN = 1        #캐릭터 방향 정의 변수 (아래쪽)
DIR_LEFT = 2        #캐릭터 방향 정의 변수 (왼쪽)
DIR_RIGHT = 3       #캐릭터 방향 정의 변수 (오른쪽)
ANIMATION = [0,1,0,2]   #애니메이션 번호 정의 리스트 (3장의 스프라이트 이미지를 반복 싸이클을 4로 애니메이션)
tmr = 0             #타이머 변수
score = 0           #점수 변수

pen_x = 90          #펜펜의 x좌표
pen_y = 90          #펜펜의 y좌표
pen_d = 0           #펜펜의 방향 변수
pen_a = 0           #펜펜의 이미지 번호

red_x = 630          #레드의 x좌표
red_y = 450          #레드의 y좌표
red_d = 0           #레드의 방향 변수
red_a = 0           #레드의 이미지 번호

map_data = [ [0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0],      #2차원 9행x12열 리스트 미로데이터 정의
             [0, 2, 3, 3, 2, 1, 1, 2, 3, 3, 2, 0],
             [0, 3, 0, 0, 3, 3, 3, 3, 0, 0, 3, 0],
             [0, 3, 1, 1, 3, 0, 0, 3, 1, 1, 3, 0],
             [0, 3, 2, 2, 3, 0, 0, 3, 2, 2, 3, 0],
             [0, 3, 0, 0, 3, 1, 1, 3, 0, 0, 3, 0],
             [0, 3, 1, 1, 3, 3, 3, 3, 1, 1, 3, 0],
             [0, 2, 3, 3, 2, 0, 0, 2, 3, 3, 2, 0],
             [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
             ]

def draw_txt(txt,x,y,siz,col):      #그림자를 포함해서 문자열(txt)를 (x,y)위치에 siz 크기, col 색깔로 표시함수
    fnt = ('Times New Roman',siz,'bold')    #폰트 정의
    canvas.create_text(x+2,y+2,text=txt,fill='black',font=fnt,tag='SCREEN') #문자열 그림자(2픽셀씩 우측 하단에 그린다.)
    canvas.create_text(x,y, text=txt, fill=col, font=fnt, tag='SCREEN')     #지정한 색깔(col)로 문자열(txt) 표시

def draw_screen():                  #게임 화면 미로 그리기 함수
    canvas.delete('SCREEN')         #모든 화면 삭제
    for y in range(9):              #y=0,1,2,...,8 (9행)
        for x in range(12):         #x=0,1,2,...,11(12열)
            canvas.create_image(x*60+30, y*60+30, image=img_bg[map_data[y][x]], tag='SCREEN') #60x60 이미지 칩의 중심이 (30,30)
    canvas.create_image(pen_x,pen_y,image=img_pen[pen_a],tag='SCREEN')     #펜펜 이미지 표시
    canvas.create_image(red_x, red_y, image=img_red[red_a], tag='SCREEN')  # 레드 이미지 표시
    draw_txt('SCORE '+str(score),200,30,30,'white')     #점수 표시 함수 호출

def check_wall(cx,cy,di,dot):           #지정한 방향에 벽 존재하는지 검사 존재한다면 True 리턴   (dot인자: 한번에 움직이는 픽셀크기)
    chk = False                     #chk 변수에 False 할당
    if di == DIR_UP:                #위쪽인 경우
        mx = (cx-30) // 60          #cx에서 좌 (cx-30)의 맵데이터 좌표로 변환
        my = (cy-30-dot) // 60      #cy좌표를 상 (-30-dot)의 맵데이터 좌표로 변환 (맵데이터 9행 12열)
        if map_data[my][mx] <= 1:   #좌상 방향이 맵데이터가 0,1은 벽
            chk = True
        mx = (cx + 29) // 60        #cx에서 우 (cx+29)의 맵데이터 좌표로 변환
        if map_data[my][mx] <= 1:   #우상 방향이 맵데이터가 0,1은 벽
            chk = True
    if di == DIR_DOWN:              #아래쪽인 경우
        mx = (cx-30) // 60          #cx에서 좌 (cx-30)의 맵데이터 좌표로 변환
        my = (cy+29+dot) // 60      #cy좌표를 하 (+29+dot)의 맵데이터 좌표로 변환 (맵데이터 9행 12열)
        if map_data[my][mx] <= 1:   #좌하 방향이 맵데이터가 0,1은 벽
            chk = True
        mx = (cx + 29) // 60        #cx에서 우 (cx+29)의 맵데이터 좌표로 변환
        if map_data[my][mx] <= 1:   #우하 방향이 맵데이터가 0,1은 벽
            chk = True
    if di == DIR_LEFT:              #왼쪽인 경우
        mx = (cx-30-dot) // 60      #cx에서 좌 (cx-30-dot)의 맵데이터 좌표로 변환
        my = (cy-30) // 60          #cy좌표를 상 (-30)의 맵데이터 좌표로 변환 (맵데이터 9행 12열)
        if map_data[my][mx] <= 1:   #좌상 방향이 맵데이터가 0,1은 벽
            chk = True
        my = (cy + 29) // 60        #cy에서 우 (cy+29)의 맵데이터 좌표로 변환
        if map_data[my][mx] <= 1:   #좌하 방향이 맵데이터가 0,1은 벽
            chk = True
    if di == DIR_RIGHT:             #오른쪽인 경우
        mx = (cx+29+dot) // 60      #cx에서 우 (cx+29+dot)의 맵데이터 좌표로 변환
        my = (cy-30) // 60          #cy좌표를 상 (-30)의 맵데이터 좌표로 변환 (맵데이터 9행 12열)
        if map_data[my][mx] <= 1:   #우상 방향이 맵데이터가 0,1은 벽
            chk = True
        my = (cy + 29) // 60        #cy에서 하 (cy+29)의 맵데이터 좌표로 변환
        if map_data[my][mx] <= 1:   #우하 방향이 맵데이터가 0,1은 벽
            chk = True


    return chk

def move_penpen():                  #펜펜의 이동함수
    global score, pen_x, pen_y, pen_d, pen_a             #전역변수 참조
    if key == 'Up':                 #key symbol 중에서 'Up' 위쪽 화살표 눌렀을 때
        pen_d = DIR_UP
        if check_wall(pen_x,pen_y,pen_d, 20) == False: #위쪽 방향이 벽인지 검사
            pen_y = pen_y - 20      #한번에 60픽셀 이동
    if key == 'Down':               #key symbol 중에서 'Down' 아래쪽 화살표 눌렀을 때
        pen_d = DIR_DOWN
        if check_wall(pen_x,pen_y,pen_d, 20) == False: #아래쪽 방향이 벽인지 검사
            pen_y = pen_y + 20      #한번에 60픽셀 이동
    if key == 'Left':               #key symbol 중에서 'Left' 왼쪽 화살표 눌렀을 때
        pen_d = DIR_LEFT
        if check_wall(pen_x,pen_y,pen_d, 20) == False: #왼쪽 방향이 벽인지 검사
            pen_x = pen_x - 20      #한번에 60픽셀 이동
    if key == 'Right':              #key symbol 중에서 'Right' 위쪽 화살표 눌렀을 때
        pen_d = DIR_RIGHT
        if check_wall(pen_x,pen_y,pen_d, 20) == False: #오른쪽 방향이 벽인지 검사
            pen_x = pen_x + 20      #한번에 60픽셀 이동
    pen_a = pen_d*3 + ANIMATION[tmr % 4]    #pen_d(0,1,2,3) * 3 -> (0,3,6,9) + ANIMATION[0..3] (0,1,0,2)
    mx = pen_x // 60                #펜펜 x 좌표의 맵데이터 좌표 변환
    my = pen_y // 60                #펜펜 y 좌표의 맵데이터 좌표 변환
    if map_data[my][mx] == 3:       #펜펜이 사탕 이미지에 들어 가면
        score += 100                #점수 추가
        map_data[my][mx] = 2       #사탕 제거

def move_enemy():                   #레드 이동 함수
    global red_x, red_y, red_d, red_a #전역변수 선언
    speed = 10                      #레드 속도 10픽셀
    if red_x % 60 == 30 and red_y % 60 == 30:   #레드가 정확한 칸 중간 위치에 있으면
        red_d = random.randint(0,3) #randint함수는 (시작,끝)  그 사이의 랜덤 정수를 반환
    if red_d == DIR_UP:             #레드가 위쪽을 향할 경우
        if check_wall(red_x,red_y, red_d, speed) == False:  #해당 방향이 벽이 아니라면
            red_y = red_y - speed
    if red_d == DIR_DOWN:             #레드가 아래쪽을 향할 경우
        if check_wall(red_x,red_y, red_d, speed) == False:  #해당 방향이 벽이 아니라면
            red_y = red_y + speed
    if red_d == DIR_LEFT:             #레드가 왼쪽을 향할 경우
        if check_wall(red_x,red_y, red_d, speed) == False:  #해당 방향이 벽이 아니라면
            red_x = red_x - speed
    if red_d == DIR_RIGHT:             #레드가 오른쪽을 향할 경우
        if check_wall(red_x,red_y, red_d, speed) == False:  #해당 방향이 벽이 아니라면
            red_x = red_x + speed
    red_a = red_d * 3 + ANIMATION[tmr%4]  #레드애니메이션 이미지 번호 (0,1,..,11) 계산

def main():                         #메인 루프
    global key,koff,tmr             #전역변수 참조
    tmr += 1                        #tmr 변수 1 증가
    draw_screen()                   #화면 그리기
    move_penpen()                   #펜펜 이동
    move_enemy()                    #레드 이동동
   #if koff == True:               # Windows koff 가 True 이면 (키를 눌렀다 뗐으면)
    #    key = ''                   # Windows key symbol 변수 초기화
    #    koff = False               # Windows koff 를 False 로 설정
    root.after(100,main)            #100ms 이후에 main 함수 다시 실행

root = tkinter.Tk()                 #윈도우 객체 생성
root.title('아슬아슬 펭귄 미로')       #윈도우 타이틀
root.resizable(False,False)         #윈도우 크기 고정
canvas = tkinter.Canvas(width=720,height=540)   #캔버스 크기, (720/60=12열) (540/60=9행) 미로 이미지 60x60
canvas.pack()                       #캔버스 압축배치
img_bg = [
    tkinter.PhotoImage(file='image_penpen/chip00.png'), #벽
    tkinter.PhotoImage(file='image_penpen/chip01.png'), #벽
    tkinter.PhotoImage(file='image_penpen/chip02.png'), #방
    tkinter.PhotoImage(file='image_penpen/chip03.png'), #캔디
]
img_pen = [                                             #펜펜이미지 리스트
    tkinter.PhotoImage(file='image_penpen/pen00.png'),
    tkinter.PhotoImage(file='image_penpen/pen01.png'),
    tkinter.PhotoImage(file='image_penpen/pen02.png'),
    tkinter.PhotoImage(file='image_penpen/pen03.png'),
    tkinter.PhotoImage(file='image_penpen/pen04.png'),
    tkinter.PhotoImage(file='image_penpen/pen05.png'),
    tkinter.PhotoImage(file='image_penpen/pen06.png'),
    tkinter.PhotoImage(file='image_penpen/pen07.png'),
    tkinter.PhotoImage(file='image_penpen/pen08.png'),
    tkinter.PhotoImage(file='image_penpen/pen09.png'),
    tkinter.PhotoImage(file='image_penpen/pen10.png'),
    tkinter.PhotoImage(file='image_penpen/pen11.png')
    ]
img_red = [                                             #레드이미지 리스트
    tkinter.PhotoImage(file='image_penpen/red00.png'),
    tkinter.PhotoImage(file='image_penpen/red01.png'),
    tkinter.PhotoImage(file='image_penpen/red02.png'),
    tkinter.PhotoImage(file='image_penpen/red03.png'),
    tkinter.PhotoImage(file='image_penpen/red04.png'),
    tkinter.PhotoImage(file='image_penpen/red05.png'),
    tkinter.PhotoImage(file='image_penpen/red06.png'),
    tkinter.PhotoImage(file='image_penpen/red07.png'),
    tkinter.PhotoImage(file='image_penpen/red08.png'),
    tkinter.PhotoImage(file='image_penpen/red09.png'),
    tkinter.PhotoImage(file='image_penpen/red10.png'),
    tkinter.PhotoImage(file='image_penpen/red11.png')
    ]
root.bind('<Key>',key_down)         #키를 눌렀을 때 실행할 함수 key_down 지정
root.bind('<KeyRelease>',key_up)    #키를 눌렀다 뗐을 때 실행할 함수 key_up 지정
main()                              #main 함수 호출
root.mainloop()                     #윈도우 표시