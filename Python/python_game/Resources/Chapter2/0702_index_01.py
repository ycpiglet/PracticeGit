import tkinter

fnt1 = ('Times New Roman', 20, 'bold')
fnt2 = ('Times New Roman', 40, 'bold')

index = 0           # 게임 진행을 관리하는 인덱스 0: 타이틀 화면, 1: 게임중, 2: 게임 종료
timer = 0           # 타이머 변수 : 게임 종료화면에서 일정 시간 흐른 후 타이틀 화면으로 자동 전환

key = ''            # 키 값을 대입할 전역 변수

def key_down(e):
    global key          # 전역변수 참조를 알림
    key = e.keysym      # key의 심볼(symbol)로 받는다

def main():
    global index, timer         # 전역변수 참조
    canvas.delete('STATUS')     # tag='STATUS'인 object들을 삭제
    timer += 1                  # 100ms마다 main 함수를 호출하기 때문에 timer 변수는 100ms마다 1 증가
    canvas.create_text(200, 30, text='index '+str(index), fill='white', font=fnt1, tag='STATUS')
    canvas.create_text(400, 30, text='timer '+str(timer), fill='cyan', font=fnt1, tag='STATUS')

    if index == 0:      # 타이틀 화면
        if timer == 1:
            canvas.create_text(300, 150, text='타이틀 ' + str(index), fill='white', font=fnt1, tag='TITLE')
            canvas.create_text(300, 300, text='Press [SPACE] Key ' + str(timer), fill='lime', font=fnt2, tag='TITLE')
            
        if key == 'space':
            canvas.delete('TITLE')      # tag='TITLE'인 객체들을 삭제
            canvas.create_rectangle(0, 0, 600, 400, fill='blue', tag='GAME')
            canvas.create_text(300, 150, text='게임 중', fill='white', font=fnt2, tag='GAME')
            canvas.create_text(300, 350, text='[E] 종료', fill='lime', font=fnt2, tag='GAME')
            index = 1       # 게임 진행 status를 게임중(index=1)로 변경
            timer = 0       # timer 초기화
            
    if index == 1:      # 게임 중일 때
        canvas.delete('GAME')  # tag='TITLE'인 객체들을 삭제
        canvas.create_rectangle(0, 0, 600, 400, fill='maroon', tag='OVER')
        canvas.create_text(300, 150, text='GAME OVER', fill='red', font=fnt2, tag='OVER')
        index = 2       # 게임 종료 status로 변경
        timer = 0       # timer 초기화
        
    if index == 2:
        if timer == 30: # 게임 종료 상태에서 3초(3000ms) 후
            canvas.delete('OVER')
            index = 0   # 타이틀 화면 status 변경
            timer = 0   # timer 초기화
        
        
    root.after(100, main) # 100ms 후에 main 함수 다시 호출

root = tkinter.Tk()
root.title('인덱스와 타이머')
root.bind('<Key>', key_down)        # key, key_press, key_down 모두 동일한 의미, 키를 눌렀을 때 실행되는 함수 지정
canvas = tkinter.Canvas(width=600, height=400, bg='black')
canvas.pack()
main()

root.mainloop()