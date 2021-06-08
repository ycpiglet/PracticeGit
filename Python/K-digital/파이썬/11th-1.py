datafile = open('textfile.txt', 'a', encoding='utf-8')

text = input('Input : ')
datafile.write(text + '\n')

datafile.close()