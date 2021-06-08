class SimpleTest():
    a = 0
    prefix = 'You said : '
    postfix = '\n' + '-'*20 + '\n'

    def print_without_skip(self, data):
        if 'skip' in data:
            print('Reject!!')
            return  
        else:
            print(data)

        print('------------------------------')

        self.print_with_fix(data)

    def print_with_fix(self, data):
        print(self.prefix + data + self.postfix)


simple1 = SimpleTest()
simple2 = SimpleTest()
simple1.print_without_skip('bad')
simple1.print_without_skip('skip test')

simple1.print_with_fix('test')

