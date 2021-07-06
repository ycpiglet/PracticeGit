class Player:                       # 클래스 Player (딜러와 플레이어 객체를 만들 때 사용)
    def __init__(self, name):       # name 인자
        self.name = name
        self.cards = []             # Card 클래스 객체
        self.N = 0                  # 현재 가지고 있는 카드 갯수
    
    def inHand(self):               # 현재 가지고 있는 카드 갯수를 반환하는 함수
        return self.N
    
    def addCard(self, c):           # 인자 c : Card 클래스 객체
        self.cards.append(c)        # self.cards 리스트에 추가
        self.N += 1                 # 갖고 있는 카드 갯수 1 증가

    def reset(self):                # 초기화 함수
        self.N = 0
        self.cards.clear()          # Card 클래스 객체 리스트를 clear

    def value(self):                # Player가 갖고 있는 카드들의 점수를 계산해서 반환
        # 일단 모든 ACE는 11로 계산
        # 만약 점수가 21이 넘어가면 갖고 있는 ACE를 하나씩 1로 변경한다.
        #
        pass