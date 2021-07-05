from tkinter import *

class MainGUI:
    def check(self):        # 가로 3줄, 세로 3줄 대각선 2줄 검사, 같은 글자일 때는 승자 존재
        for i in range(3):     # 각 행, 열에 대해서 검사
            ch = self.matrix[i][0]['text']      # i행 0열 문자
            if ch != ' ' and ch == self.matrix[i][1]['text'] and ch == self.matrix[i][2]['text']:       # 한 행이 모두 일치하는 경우
                return ch       # 승자의 글자(O, x)를 반환
            ch = self.matrix[0][i]['text']      # o행 i열 문자
            if ch != ' ' and ch == self.matrix[1][i]['text'] and ch == self.matrix[2][i]['text']:       # 한 열이 모두 일치하는 경우
                return ch       # 승자의 글자(O, x)를 반환
        ch = self.matrix[1][1]['text']      # 1행 1열 검사
        if ch != ' ' and ch == self.matrix[0][0]['text'] and ch == self.matrix[2][2]['text']:  # 한 행이 모두 일치하는 경우
            return ch  # 승자의 글자(O, x)를 반환
        if ch != ' ' and ch == self.matrix[0][2]['text'] and ch == self.matrix[2][0]['text']:  # 한 행이 모두 일치하는 경우
            return ch  # 승자의 글자(O, x)를 반환
        # 비긴 경우 검사
        for r in range(3):
            for c in range(3):
                if self.matrix[r][c]['text'] == ' ':
                    return ' '
        return '@'
        '''
        flag = True # bool 변수, 모든 버튼이 눌린 것을 가정
        for r in range(3):
            for c in range(3):
                if self.matrix[r][c]['text'] == ' ':     # 빈칸이 하나라도 존재하면
                    flag = False
                    break
            if flag == False:
                break
        if flag:        # True인 경우는 모든 버튼이 눌린 경우
            return '@'
        '''
        return ' '

    def pressed(self, row, col):
        if not self.done and self.matrix[row][col]['text'] == ' ':      # 종료가 아니고, 빈 버튼인 경우
            if self.turn:       # True : X 차례
                self.matrix[row][col]['image'] = self.imageX
                self.matrix[row][col]['text'] = 'X'
            else:               # False : O 차례
                self.matrix[row][col]['image'] = self.imageO
                self.matrix[row][col]['text'] = 'O'
            self.turn = not self.turn       # 다음 플레이어로 넘김
            # 승패 검사하기
            if self.check() == '@':     # 이긴 사람이 있으면 'O', 'X' 반환하고, 비겼으면 '@' 반환, 종료되지 않았으면 ' '반환
                self.explain.set('비김')
            elif self.check() != ' ':       # 승자가 존재하는 경우
                self.explain.set(self.check() + '가 이겼습니다.')
                self.done = True
            elif self.turn:
                self.explain.set('플레이어 X 차례')
            else:
                self.explain.set('플레이어 O 차례')

    def refresh(self):
        self.turn = True
        self.done = False
        self.explain.set('플레이어 X 차례')
        for r in range(3):
            for c in range(3):
                self.matrix[r][c]['image'] = self.imageE
                self.matrix[r][c]['text'] = ' '

    def __init__(self):         # 생성자
        window = Tk()
        window.title('틱택토')
        self.turn = True        # 차례(순서)를 관리하는 변수 True : X, False : O (bool 변수)
        self.done = False       # 게임 종료 여부를 관리하는 변수 (bool 변수)
        frame = Frame(window)   # Container 위젯
        frame.pack()            # 압축배치자 (세로로 붙인다)
        # 버튼 격차 3x3 : 이미지
        self.imageX = PhotoImage(file='image/x.gif')        # PhotoImage 멤버 변수
        self.imageO = PhotoImage(file='image/o.gif')        # PhotoImage 멤버 변수
        self.imageE = PhotoImage(file='image/empty.gif')    # PhotoImage 멤버 변수
        self.matrix = []        # 3x3 격자를 만드는 2차원 리스트
        for r in range(3):              # range는 수열을 만드는 파이썬 내장 함수, r은 raw의 줄임말
            self.matrix.append([])      # [[B,B,B], [ ], [ ]]
            for c in range(3):          # c는 column의 줄임말
                self.matrix[r].append(Button(frame, image=self.imageE, text=' ',
                                             command=lambda row=r, col=c:self.pressed(row, col)))
                self.matrix[r][c].grid(row=r, column=c)
        self.explain = StringVar()      # 차례/승패를 알려주는 문자열 변수
        Label(window, textvariable=self.explain).pack()
        Button(window, text='다시 시작', command=self.refresh).pack()
        window.mainloop()

MainGUI()