class people:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def sayhi(self):
        print('hi')

    @classmethod
    def test1(cls):
        print('这是个类方法')

    @staticmethod
    def test2():
        print('这是个静态方法')

people.test1()

p = people(name='aaa', age=1)
p.test1()

p.test2()
p.test1()