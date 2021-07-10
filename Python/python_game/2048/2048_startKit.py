from tkinter import *
from tkinter import messagebox
import random


class Game2048:
    # 숫자 배경 색 사전
    bg_color = {
        2: '#eee4da',
        4: '#ede0c8',
        8: '#edc850',
        16: '#edc53f',
        32: '#f67c5f',
        64: '#f65e3b',
        128: '#edcf72',
        256: '#edcc61',
        512: '#f2b179',
        1024: '#f59563',
        2048: '#edc22e',
    }
    # 숫자 색 사전
    color = {
        2: '#776e65',
        4: '#f9f6f2',
        8: '#f9f6f2',
        16: '#f9f6f2',
        32: '#f9f6f2',
        64: '#f9f6f2',
        128: '#f9f6f2',
        256: '#f9f6f2',
        512: '#776e65',
        1024: '#f9f6f2',
        2048: '#f9f6f2',
    }

    #nxn 격자(self.gridCell) 중에서 비어있는(숫자 0) cell들만 골라서
    #cells 리스트에 그 위치 (r,c)를 넣고 랜덤하게 골라서 숫자 2로 설정한다.
    def random_cell(self):
        pass

    #nxn 2D 라벨 격자 (self.board) 의 배경색과 숫자색 칠하기
    def paintGrid(self):
        pass

    #행과 열을 바꿔서 전치 행렬로 만듦
    def transpose(self):
        #zip([[1,2,3],[4,5,6],[7,8,9]] : (1,4,7), (2,5,8), (3,6,9) 로 차례로 묶어서 튜플로 만듦
        pass

    #모든 행에 대해서 reverse
    def reverse(self):
        pass

    #nxn 격자의 모든 행에 대해서 left 방향으로 비어있는 셀이 있으면 끝까지 이동
    def compressGrid(self):


        #nxn 비어 있는 2D 격자 셀 temp 생성
        #self.gridCell 의 숫자 셀(0이 아닌셀)은 temp의 좌측부터 비어 있는 셀(숫자 0)에 넣는다.
        pass

    #좌에서 우로 인접셀이 같으면 merge
    def mergeGrid(self):
        pass

    #셀이 꽉 찬경우에 merge 할 셀이 남아 있다면 True 리턴
    def can_merge(self):
        # 가로로 인접한 셀 merge 가능 유무 체크


        # 세로로 인접한 셀 merge 가능 유무 체크

        return False


    #키 입력 Up, Down, Left, Right 이벤트 처리 함수
    def link_keys(self,event):
        if self.end or self.won:    #게임 종료이면 키 입력 처리 안함
            return
        #변수 False 초기화
        self.compress = False   #nxn 격자 모든 행에 대해서 Left 방향으로 비어 있는 셀로 이동했으면 True
        self.merge = False
        self.moved = False

        key = event.keysym
        if key == 'Up':
            self.transpose()            # 행과 열 전치
            self.compressGrid()         # 좌로 비어있는 셀이 없도록 밀착
            self.mergeGrid()            # 좌우 인접셀 merge
            self.moved = self.compress or self.merge # compress 했거나 merge 했으면 moved = True 설정
            self.compressGrid()         # 다시 한번 좌로 비어있는 셀이 없도록 밀착
            self.transpose()            # 행과 열 다시한번 전치
        elif key == 'Down':
            pass
        elif key == 'Left':
            pass
        elif key == 'Right':
            pass
        else:
            pass



        #2048 승리하지 않고 비어 있는 셀이 있다면 flag = 1 로 설정




    def __init__(self,size):
        self.n = size       #size에 따라서 4x4, 5x5, 6x6 등으로 게임판 선택 가능
        self.window = Tk()
        self.window.title('2048 Game')
        self.gameArea = Frame(self.window, bg='azure3') #게임판 프레임 생성
        self.gridCell = [[0]*self.n for _ in range(self.n)]   # n x n 숫자 격자셀 0(비어있음) 으로 초기화

        self.compress = False   #좌로 비어 있는 셀로 이동 유무나타내는 변수
        self.merge = False      #좌우 인접셀 숫자가 같으면 merge 유무나타내는 변수
        self.moved = False      #compress 혹은 merge 유무나타내는 변수
        self.end = False        #게임 종료 변수
        self.won = False        #게임 승리 변수
        self.score = 0          #게임 점수

        self.board = [] #n x n 2D 격자 라벨 생성
        for r in range(self.n):
            rows = []
            for c in range(self.n):
                l = Label(self.gameArea, text='',bg='azure4',font=('arial',22,'bold'),width=4,height=2)
                l.grid(row=r,column=c,padx=7,pady=7) #r행 c열 격자 라벨생성, padx=7, pady=7 좌,상 7포인트 간격
                rows.append(l)
            self.board.append(rows)
        self.gameArea.pack()

        self.random_cell()  #랜덤하게 숫자 2 위치 선택
        self.random_cell()  #랜덤하게 숫자 2 위치 선택
        self.paintGrid()    #self.board nxn 2D 라벨 배경과 숫자색 색칠
        self.window.bind('<Key>', self.link_keys)   #키입력 이벤트 함수 self.link_keys 연결
        self.window.mainloop()


Game2048(4)






















