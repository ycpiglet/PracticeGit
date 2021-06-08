class SimpleTest():
    CTRL = 1
    ALT = 2
    DELETE = 3
    F1 = 4
    static_var = 0

    def __init__(self):
        self.instance_var = 100

    def instance_function(self):
        print('instance')
    
    def static_function():
        print('static')

SimpleTest.static_function()
simple = SimpleTest()
simple.instance_function()

# print(SimpleTest.static_var)

# simple = SimpleTest()
# print(simple.keydown(SimpleTest.CTRL))