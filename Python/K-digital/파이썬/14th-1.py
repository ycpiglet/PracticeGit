import traceback 

with open('data.csv', 'r', encoding='utf-8') as f:
    while True:
        line = f.readline().strip()
        if not line:
            break
        
        data = line.split(', ')
        # if data[-1].isdigit()
        try:
            last_value = int(data[-1])
            print(last_value + 100)
        except :
            # print('Not int')
            traceback.print_exc()
        