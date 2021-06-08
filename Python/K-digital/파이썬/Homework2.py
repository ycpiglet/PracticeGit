with open('large_bike.csv', 'r', encoding='utf-8') as textfile:

    userInput = input('검색할 지역을 입력하세요 : ')
    count = 1

    try:
        while True:
            line = textfile.readline().strip()
            data = line.split(',')
            season = ''
            
            if line == '': # if not line :
                if count == 1:
                    print("그런 지역은 없습니다! 지역명을 확인해주세요.")
                else:
                    print('모두 찾았습니다! 검색을 완료합니다.')
                break

            if userInput == data[12]:
                if data[1] == '1':
                    season = '봄'
                elif data[1] == '2':
                    season = '여름'
                elif data[1] == '3':
                    season = '가을'
                elif data[1] == '4':
                    season = '겨울'
                
                result = 'No.' + str(count) + '   ' + season + ', casual : ' + data[9] + ', registered : ' + data[10]
                print(result)
                count += 1
        
    except Exception as e:
        print(e)