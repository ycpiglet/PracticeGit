import os

# f = open('wise_saying.txt', 'w')
# f.write('Life is too short, you need python')
# f.close()

try:
    f = open('wise_saying.txt', 'r')
    if f.read() == 'Life is too short, you need python':
        print(f.read())
        
    f.close()

except:
    print('내용이 일치하지 않습니다')
