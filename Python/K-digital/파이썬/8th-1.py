def printSkip(data):
    if 'skip' in data:
        print('Reject')
        return
    else:
        print(data)



user_input = ''
while user_input != 'quit':
    user_input = input('Input : ')
    printSkip(user_input)
