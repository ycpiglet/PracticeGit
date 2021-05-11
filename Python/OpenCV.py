coffee = 5
money = int(input("돈을 넣어 주세요 (커피 한잔 300원): "))
print('%d을 넣었습니다' %(money))

while 1:

    cof = int(input("커피 뽑을까요?(커피 한잔 300원): 1/2"))
    if cof==1:
        if money == 300:
            print("커피를 줍니다.")
            coffee -= 1

        elif money > 300:
            money -= 300
            print("거스름돈 %d를 주고 커피를 줍니다." %(money))
            coffee -= 1
            print("남은 커피의 양은 %d개 입니다." % coffee)
        else:
            print("돈을 다시 돌려주고 커피를 주지 않습니다.")

    else:
        print("거스름돈 %d를 반납합니다. 커피 %d 잔 남았습니다." %(money,coffee))

    if coffee == 0:
        print("커피가 다 떨어졌습니다. 판매를 중지합니다.")
        break