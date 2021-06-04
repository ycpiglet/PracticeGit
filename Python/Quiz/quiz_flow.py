import os

# f = open('wise_saying.txt', 'w')
# f.write('Life is too short, you need python')
# f.close()

with open('wise_saying.txt', 'r', encoding='utf-8') as f:
    string = f.read()

    try:

        if string == 'Life is too short, you need python':
            print(string)
        
        else:
            raise ValueError()

    except:
        print('내용이 일치하지 않습니다')
