import matplotlib.pyplot as plt # matplot 모듈의 pyplot을 이용해서 그림을 그림
import webbrowser # 웹브라이저를 활용할 수 있게 함
import threading # threading 모듈은 파이썬에서 스레드를 생성할 수 있게 함
import datetime # 현재 날짜, 시간 알려주는 기능
from matplotlib.widgets import Button # 버튼위젯 불러오기
from matplotlib.widgets import TextBox # 텍스트상자 위젯 불러오기
from matplotlib import gridspec # 격자(Grid) 설정

global time_set # 전역 변수(Global)으로 설정
global time_thread
global time_text

def time_elasped(): # 함수 만들기

    global time_thread # 일반 변수가 아닌, 전역 변수라는 것을 구분함
    global time_set

    time_set[0] = time_set[0] - 1 # time_set 함수의 첫 번째 값(Index = 0)인 3600에서 1씩 감소
    time_set[1] = time_set[1] + 1 # time_set 함수의 두 번째 값(Index = 1)인 0에서 1씩 증가

    if time_set[0] <= 0: # 1시간이 지나면 (3600에서 1씩 감소해서 0이 되면)

        time_thread.cancel()
        webbrowser.open("https://www.youtube.com/watch?v=kErwetO-VEk&ab_channel=D.N.AMusic") # 원하는 노래를 튼다

        return 0 # 전부 실행했으면 0을 반납

    ax1.clear() # 타이머 화면(2번째 그래프) 클리어
    ax1.pie(time_set, startangle=90, colors=["red", "white"]) # pit형으로 표현, 빨간색과 하얀색으로 구분
    plt.draw()

    print(datetime.datetime.now()) # 현재 날짜와 시각을 프린트

    time_thread = threading.Timer(1, time_elasped)  # 1초마다 쓰레드 실행
    time_thread.start()  # start 버튼 쓰레드 실행

def time_start(val):

    global time_set # 전역 변수 불러오기
    global time_text
    global time_thread

    try:
        input_time = int(time_text.text) # 입력된 text를 int형으로 변환
    except:
        input_time = 60

        if input_time > 0 and input_time <= 60: # 입력된 값이 0~60이면 그대로 실행
            start_time = input_time * 60
            left_time = 3600 - start_time

        else: # 60이상이면 60으로 취급
            input_time = 60
            start_time = input_time * 60
            left_time = 3600 - start_time

        time_set = list([start_time, left_time]) # 변경된 시간으로 적용

    try:
        time_thread.cancel() # start 버튼을 누르면 쓰레드 취소
    except:
        pass

    time_elasped() # 전부 실행하면 time_elasped() 함수 실행

if __name__ == '__main__':

    fig = plt.figure(figsize=(5, 5))  # 전체 사이즈 설정

    gs = gridspec.GridSpec(nrows=3, ncols=1, height_ratios=[1, 10, 1]) # 3개의 행(nrow)과 1개의 열(ncol)을 1:10:1 비율로 생성

    ax0 = plt.subplot(gs[0]) # 3개의 그래프 중 1번째 (Index = 0)
    ax1 = plt.subplot(gs[1]) # 3개의 그래프 중 2번째 (Index = 1)
    ax2 = plt.subplot(gs[2]) # 3개의 그래프 중 3번째 (Index = 2)

    ax0.axis('off') # 격자(Grid) 없애기
    ax1.axis('off') # 격자(Grid) 없애기
    ax2.axis('off') # 격자(Grid) 없애기

    ax0.text(0.2, 0.8, "Time Timer").set_fontsize(25) # ax0 그래프의 (0.2, 0.8)위치에 Time Timer라는 글자 그리기 (폰트 25)

    start_pos = plt.axes([0.7, 0.05, 0.1, 0.075]) # 시작 버튼 그리기
    start = Button(start_pos, "START") # start 상자를 버튼으로 만들고 START라 표현

    text_pos = plt.axes([0.6, 0.05, 0.08, 0.075]) # 입력받을 텍스트 상자 그리기

    time_set = list([3600,0]) # 1시간을 3600초로 표현
    ax1.pie(time_set, startangle=90, colors=["red", "white"])

    time_text = TextBox(text_pos, label = "insert time to check ") # 안내 메시지 상자 
    start.on_clicked(time_start) # start 버튼 클릭하면 time_start 함수 실행

    plt.show() # 그래프를 시각화해서 보여줌