class myclass:
    pass

class people:

    def __init__(self, name, age):
        # self._protect_var = 10
        # self.__private_var = 10
        self.__name = name
        self.__age = age

    @property
    def name(self):
        return self.__name

    @property
    def age(self):
        return self.__age

    @name.setter
    def name(self, name):
        self.__name = name

    @age.setter
    def age(self, age):
        self.__age = age

    def sayhi(self):
        print('hi, My name is {}, ans I\'m {}'.format(self.name, self.age))

someone = people(name='Tom', age=20)
print(someone.name)
print(someone.age)

someone.sayhi()

someone.name = 'Som'
someone.age = 23

print(someone.name)
print(someone.age)

print(dir(someone))