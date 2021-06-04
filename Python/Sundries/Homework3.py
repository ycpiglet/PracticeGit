with open('large_bike.csv', 'r', encoding='utf-8') as textfile:

    userInput = input('검색할 지역을 입력하세요 : ')
    count = 1
    total = []
    result = {}

    try:
        while True:
            line = textfile.readline().strip()
            data = line.split(',')
            season = ''
            date = ''

            if line == '': # if not line :
                total = list(result.keys())
                total.sort()
                for i in total:
                    count += 1
                    print('No.' + str(count) + '   ' + str(result[i]))

                if count > 2:
                    print('모두 찾았습니다! 검색을 완료합니다.')
                else:
                    print("그런 지역은 없습니다! 지역명을 확인해주세요.")
                    
                break
            
            if userInput == data[12]:
                # date = data[0].replace(' ', '-')
                date = data[0][:10]
                date = date.split('-')

                mod_data = str(date[0]) + '.' + str(date[1]) + '.' + str(date[2]) + ', casual : ' + data[9] + ', registerd : ' + data[10]
                result[data[0]] = mod_data
        
    except Exception as e:
        print(e)