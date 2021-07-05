from tkinter import *

class MainGUI:
    def check(self):        # 가로 4개씩, 세로 4개씩, 대각선
        # 가로 검사
        for r in range(6):  # c=0,1,2,3
            for c in range(4):
                ch = self.matrix[r][c]['text']
                if ch != ' ' and ch == self.matrix[r][c+1]['text'] and ch == self.matrix[r][c+2]['text'] \
                    and ch == self.matrix[r][c+3]['text']:
                    return ch
        # 세로 검사
        for r in range(3):  # r=0,1,2
            for c in range(7):
                ch = self.matrix[r][c]['text']
                if ch != ' ' and ch == self.matrix[r+1][c]['text'] and ch == self.matrix[r+2][c]['text'] \
                        and ch == self.matrix[r+3][c]['text']:
                    return ch
        # 대각선 좌상-우하
        for r in range(3):  # r=0,1,2
            for c in range(4): # c=0,1,2,3
                ch = self.matrix[r][c]['text']
                if ch != ' ' and ch == self.matrix[r+1][c+1]['text'] and ch == self.matrix[r+2][c+2]['text'] \
                        and ch == self.matrix[r+3][c+3]['text']:
                    return ch
        # 대각선 우상-좌하
        for r in range(3):  # r=0,1,2
            for c in range(3, 7):  # c=3,4,5,6
                ch = self.matrix[r][c]['text']
                if ch != ' ' and ch == self.matrix[r+1][c-1]['text'] and ch == self.matrix[r+2][c-2]['text'] \
                        and ch == self.matrix[r+3][c-3]['text']:
                    return ch
        return ' '

    def refresh(self):
        self.turn = True
        self.done = False
        self.explain.set('플레이어 X 차례')
        for r in range(6):
            for c in range(7):
                self.matrix[r][c]['image'] = self.imageE
                self.matrix[r][c]['text'] = ' '

    def pressed(self, col):
        for row in range(5, -1, -1):        # row = 5, 4, 3, 2, 1, 0
            if not self.done and self.matrix[row][col]['text'] == ' ':      # 빈 버튼인가?
                if self.turn:
                    self.matrix[row][col]['image'] = self.imageX
                    self.matrix[row][col]['text'] = 'X'
                else:
                    self.matrix[row][col]['image'] = self.imageO
                    self.matrix[row][col]['text'] = 'O'
                self.turn = not self.turn       # 차례를 넘김
                if self.check() == '@':
                    self.explain.set('이김')
                    self.done = True
                elif self.check() != ' ':       # 승자가 존재하는 경우
                    self.explain.set(self.check() + '가 이김')
                    self.done = True
                elif self.turn:
                    self.explain.set('플레이어 X 차례')
                else:
                    self.explain.set('플레이어 O 차례')
                break


    def __init__(self):     # 생성자
        window = Tk()
        window.title('4목게임')
        self.imageO = PhotoImage(file='image/o.gif')
        self.imageX = PhotoImage(file='image/x.gif')
        self.imageE = PhotoImage(file='image/empty.gif')
        frame = Frame(window)
        frame.pack()
        self.turn = True         # 차례 : True X, False O
        self.done = False        # 게임종료 여부
        self.matrix = []         # 6행 7열 버튼을 담는 리스트
        for r in range(6):
            self.matrix.append([])
            for c in range(7):
                self.matrix[r].append(Button(frame, text=' ', image=self.imageE,
                                          command=lambda col=c:self.pressed(col)))
                self.matrix[r][c].grid(row=r, column=c)     # 격자배치
        self.explain = StringVar()
        self.explain.set('플레이어 X 차례')
        Label(window, textvariable=self.explain).pack()
        Button(window, text='새로 시작', command=self.refresh).pack()

        window.mainloop()

MainGUI()