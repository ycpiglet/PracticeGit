class SimpleTest():
    my_data = 0

    def __init__(self): # Class가 호출되자 마자 시작 : Magic method
        self.my_data = 100
        print('Call init!')

simple = SimpleTest()
print(simple.my_data)

