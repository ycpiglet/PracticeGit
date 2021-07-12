from tkinter import *
from tkinter import font
from winsound import *
from Card import *
from Player import *
import random

class BlackJack:                        #클래스 BlackJack
    def pressedB50(self):
        self.betMoney += 50
        if 50 <= self.playerMoney:   # 배팅 한도 검사
            self.LbetMoney['text'] = '$'+str(self.betMoney)
            self.playerMoney -= 50
            self.LplayerMoney['text'] = 'You have $'+str(self.playerMoney)
            self.Deal['state'] = 'active'
            self.Deal['bg'] = 'white'
            PlaySound('sounds/chip.wav',SND_FILENAME)
        else:
            self.betMoney -= 50
    def pressedB10(self):
        self.betMoney += 10
        if 10 <= self.playerMoney:  # 배팅 한도 검사
            self.LbetMoney['text'] = '$' + str(self.betMoney)
            self.playerMoney -= 10
            self.LplayerMoney['text'] = 'You have $' + str(self.playerMoney)
            self.Deal['state'] = 'active'
            self.Deal['bg'] = 'white'
            PlaySound('sounds/chip.wav', SND_FILENAME)
        else:
            self.betMoney -= 10
    def pressedB1(self):
        self.betMoney += 1
        if 1 <= self.playerMoney:  # 배팅 한도 검사
            self.LbetMoney['text'] = '$' + str(self.betMoney)
            self.playerMoney -= 1
            self.LplayerMoney['text'] = 'You have $' + str(self.playerMoney)
            self.Deal['state'] = 'active'
            self.Deal['bg'] = 'white'
            PlaySound('sounds/chip.wav', SND_FILENAME)
        else:
            self.betMoney -= 1
    def hitPlayer(self,n):  #n: 카드 이미지 라벨 위치 변수
        newCard = Card(self.cardDeck[self.deckN])   #새로운 Card 객체를 cardDeck 에서 0..51 랜덤 넘버를 인자로 전달해서 생성
        self.deckN += 1         # 카드덱 인덱스 1 증가
        self.player.addCard(newCard)    # Card 객체를 player에게 추가
        p = PhotoImage(file='cards/'+newCard.filename()) # Card 객체의 filename 으로 이미지 생성
        self.LcardsPlayer.append(Label(self.window,image=p))    # 플레이어 카드 이미지 라벨 리스트에 추가
        self.LcardsPlayer[self.player.inHand()-1].image = p     # 파이썬에서 라벨 이미지 레퍼런스를 지정해야 이미지가 보임
        self.LcardsPlayer[self.player.inHand()-1].place(x=250+n*30,y=350)   #n:위치변수따라서 x위치가 달라짐

        self.LplayerPts['text']=str(self.player.value())    # 플레이어 카드 점수 표시
        PlaySound('sounds/cardFlip1.wav',SND_FILENAME)

    def hitDealerDown(self):    #딜러 첫번째 카드 뒤집어서 생성
        newCard = Card(self.cardDeck[self.deckN])   #새로운 Card 객체를 cardDeck 에서 0..51 랜덤 넘버를 인자로 전달해서 생성
        self.deckN += 1         # 카드덱 인덱스 1 증가
        self.dealer.addCard(newCard)    # Card 객체를 player에게 추가
        p = PhotoImage(file='cards/b2fv.png') # 뒤집어진 카드 이미지 생성
        self.LcardsDealer.append(Label(self.window,image=p))    # 플레이어 카드 이미지 라벨 리스트에 추가
        self.LcardsDealer[self.dealer.inHand()-1].image = p     # 파이썬에서 라벨 이미지 레퍼런스를 지정해야 이미지가 보임
        self.LcardsDealer[self.dealer.inHand()-1].place(x=250,y=150)   #고정 위치

    def hitDealer(self,n):    #딜러 카드 이미지 생성 (n에 따라서 위치 변경)
        newCard = Card(self.cardDeck[self.deckN])   #새로운 Card 객체를 cardDeck 에서 0..51 랜덤 넘버를 인자로 전달해서 생성
        self.deckN += 1         # 카드덱 인덱스 1 증가
        self.dealer.addCard(newCard)    # Card 객체를 player에게 추가
        p = PhotoImage(file='cards/'+newCard.filename()) # Card 객체의 filename 으로 이미지 생성
        self.LcardsDealer.append(Label(self.window,image=p))    # 플레이어 카드 이미지 라벨 리스트에 추가
        self.LcardsDealer[self.dealer.inHand()-1].image = p     # 파이썬에서 라벨 이미지 레퍼런스를 지정해야 이미지가 보임
        self.LcardsDealer[self.dealer.inHand()-1].place(x=280 + n*30,y=150)   #x위치는 n에 따라 변경

    def deal(self):
        self.player.reset() #카드 초기화
        self.dealer.reset() #카드 초기화
        #카드 덱 52장 shuffle 0,1,...51
        self.cardDeck = [i for i in range(52)]  #리스트 내장 기법 [0,1,2,...51]
        random.shuffle(self.cardDeck)   #셔플링
        self.deckN = 0      #카드덱 인덱스 = 0초기화

        self.hitPlayer(0)   #카드 이미지 라벨 위치 0에 카드 생성
        self.hitPlayer(1)  # 카드 이미지 라벨 위치 1에 카드 생성
        self.hitDealerDown()#딜러 카드 첫번째 이미지라벨은 뒤집어서 생성 (위치 고정)
        self.hitDealer(0)   #딜러 카드 이미지 라벨 위치 0에 카드 생성
        self.nCardsPlayer = 1   # 플레이어 카드 이미지 라벨 위치 변수 변경
        self.nCardsDealer = 0   # 딜러 카드 이미지 라벨 위치 변수 변경

        self.B50['state'] = 'disabled'
        self.B50['bg'] = 'gray'
        self.B10['state'] = 'disabled'
        self.B10['bg'] = 'gray'
        self.B1['state'] = 'disabled'
        self.B1['bg'] = 'gray'

    def checkWinner(self):
        #딜러의 뒤집어진 카드를 보여준다.
        p = PhotoImage(file='cards/'+self.dealer.cards[0].filename())   #딜러의 Card 객체 리스트에서 0번째 Card 객체에서
        self.LcardsDealer[0]['image'] = p
        self.LcardsDealer[0].image = p      #라벨 이미지 레퍼런스를 갖고 있어야 이미지가 보임

        self.LdealerPts['text'] = str(self.dealer.value())  #딜러 점수 표시

        #승패 판정
        if self.player.value() > 21:        #패
            self.Lstatus['text'] = 'Player Busts'
            PlaySound('sounds/wrong.wav',SND_FILENAME)
        elif self.dealer.value() > 21:      #승
            self.Lstatus['text'] = 'Dealer Busts'
            self.playerMoney += self.betMoney*2
            PlaySound('sounds/win.wav',SND_FILENAME)
        elif self.player.value() == self.dealer.value(): #비김
            self.Lstatus['text'] = 'Push'
            self.playerMoney += self.betMoney
        elif self.player.value() > self.dealer.value():      #승
            self.Lstatus['text'] = 'You won !'
            self.playerMoney += self.betMoney*2
            PlaySound('sounds/win.wav',SND_FILENAME)
        else:
            self.Lstatus['text'] = 'Sorry you lost!'
            PlaySound('sounds/wrong.wav', SND_FILENAME)

        # 변수들을 초기화
        self.betMoney = 0
        self.LplayerMoney.configure(text="Youhave$" + str(self.playerMoney))
        self.LbetMoney.configure(text="$" + str(self.betMoney))
        self.B50['state'] = 'disabled'
        self.B50['bg'] = 'gray'
        self.B10['state'] = 'disabled'
        self.B10['bg'] = 'gray'
        self.B1['state'] = 'disabled'
        self.B1['bg'] = 'gray'
        self.Hit['state'] = 'disabled'
        self.Hit['bg'] = 'gray'
        self.Stay['state'] = 'disabled'
        self.Stay['bg'] = 'gray'
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'active'
        self.Again['bg'] = 'white'

    def pressedHit(self):       #플레이어 카드 추가 버튼 함수
        self.nCardsPlayer += 1              #플레이어 카드 이미지 라벨의 위치 1 증가
        self.hitPlayer(self.nCardsPlayer)   # 카드 추가
        if self.player.value() > 21:        #플레이어 카드 점수가 21을 초과하면 종료해야 함
            self.checkWinner()  # 승부 결정

    def pressedStay(self):      # 플레이어가 카드를 그만 받을 때 처리 함수
        while self.dealer.value() < 17:     # 딜러는 점수가 17보다 작으면 무조건 카드를 받는다.
            self.nCardsDealer += 1          # 딜러 카드 이미지 라벨 위치 1 증가
            self.hitDealer(self.nCardsDealer)   # 딜러 카드 1 추가
        self.checkWinner()          # 승부 결정

    def pressedDeal(self):
        self.deal()
        self.Lstatus['text'] = ''   #status 라벨 초기화
        self.Hit['state'] = 'active'
        self.Hit['bg'] = 'white'
        self.Stay['state'] = 'active'
        self.Stay['bg'] = 'white'
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

    def pressedAgain(self):
        # 딜러와 플레이어 카드 라벨 이미지 삭제
        for i in (self.dealer.inHand()):
            self.LcardsDealer[i].configure(bg='green', image='')
        for i in (self.player.inHand()):
            self.LcardsPlayer[i].configure(bg='green', image='')
        self.LcardsDealer.clear()
        self.LcardsPlayer.clear()

        # 점수 라벨, 결과 라벨 초기화
        self.LdealerPts['text'] = ''
        self.LplayerPts['text'] = ''
        self.Lstatus['text'] = ''

        # 버튼 초기화
        self.B50.configure(state='active', bg='white')
        self.B10.configure(state='active', bg='white')
        self.B1.configure(state='active', bg='white')
        self.Again.configure(state='disabled', bg='gray')

    def setupButton(self):
        self.B50 = Button(self.window,text='Bet 50',width=6,height=1,font=self.fontstyle2,command=self.pressedB50)
        self.B50.place(x=50,y=500)      #절대배치
        self.B10 = Button(self.window,text='Bet 10',width=6,height=1,font=self.fontstyle2,command=self.pressedB10)
        self.B10.place(x=150,y=500)      #절대배치
        self.B1 = Button(self.window,text='Bet 1',width=6,height=1,font=self.fontstyle2,command=self.pressedB1)
        self.B1.place(x=250,y=500)      #절대배치
        self.Hit = Button(self.window,text='Hit',width=6,height=1,font=self.fontstyle2,command=self.pressedHit)
        self.Hit.place(x=400,y=500)      #절대배치
        self.Stay = Button(self.window,text='Stay',width=6,height=1,font=self.fontstyle2,command=self.pressedStay)
        self.Stay.place(x=500,y=500)      #절대배치
        self.Deal = Button(self.window, text='Deal', width=6, height=1, font=self.fontstyle2, command=self.pressedDeal)
        self.Deal.place(x=600, y=500)     # 절대배치
        self.Again = Button(self.window, text='Again', width=6, height=1, font=self.fontstyle2, command=self.pressedAgain)
        self.Again.place(x=700, y=500)     # 절대배치

        self.Hit['state'] = 'disabled'      # 'state' 속성 변경
        self.Hit['bg'] = 'gray'             # 버튼 배경색 변경
        self.Stay['state'] = 'disabled'  # 'state' 속성 변경
        self.Stay['bg'] = 'gray'  # 버튼 배경색 변경
        self.Deal['state'] = 'disabled'  # 'state' 속성 변경
        self.Deal['bg'] = 'gray'  # 버튼 배경색 변경
        self.Again['state'] = 'disabled'  # 'state' 속성 변경
        self.Again['bg'] = 'gray'  # 버튼 배경색 변경

    def setupLabel(self):               #라벨 생성 함수
        self.LbetMoney = Label(text='$0',width=6,height=1,font=self.fontstyle,bg='green',fg='cyan') #베팅머니 라벨
        self.LbetMoney.place(x=200,y=450)       #절대배치
        self.LplayerMoney = Label(text='You have $1000',width=15,height=1,font=self.fontstyle,bg='green',fg='cyan') #플레이어머니 라벨
        self.LplayerMoney.place(x=500,y=450)       #절대배치
        self.LplayerPts = Label(text='',width=2,height=1,font=self.fontstyle2,bg='green',fg='white') #플레이어 점수 라벨
        self.LplayerPts.place(x=300,y=300)       #절대배치
        self.LdealerPts = Label(text='',width=2,height=1,font=self.fontstyle2,bg='green',fg='white') #딜러 점수 라벨
        self.LdealerPts.place(x=300,y=100)       #절대배치
        self.Lstatus = Label(text='',width=15,height=1,font=self.fontstyle,bg='green',fg='white') #결과 라벨
        self.Lstatus.place(x=500,y=300)       #절대배치
    def __init__(self):
        self.window = Tk()              #윈도우 생성
        self.window.title('Black Jack')
        self.window.geometry('800x600')
        self.window.resizable(False,False)
        self.window.configure(bg='green')
        self.fontstyle = font.Font(self.window, size=24, weight='bold', family='Consolas')
        self.fontstyle2 = font.Font(self.window, size=16, weight='bold', family='Consolas')
        self.setupButton()              #버튼 설정함수 호출
        self.setupLabel()               #라벨 설정함수 호출

        self.player = Player('player')  #플레이어 객체 생성
        self.dealer = Player('dealer')  #딜러 객체 생성
        self.betMoney = 0               #베팅 머니 변수
        self.playerMoney = 1000         #플레이어 머니 변수
        self.nCardsDealer = 0           #딜러 카드 이미지 라벨의 위치변수
        self.nCardsPlayer = 0           #플레이어 카드 이미지 라벨의 위치변수
        self.LcardsDealer = []          #딜러 카드 이미지 라벨 리스트
        self.LcardsPlayer = []          #플레이어 카드 이미지 라벨 리스트
        self.deckN = 0                  #카드 덱은 (0..51) 숫자를 shuffle해서 갖고 있다. 카드 덱의 인덱스 변수
        self.window.mainloop()

BlackJack()











