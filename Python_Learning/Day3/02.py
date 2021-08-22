class animal:
    def eat(self):
        print('Animal is eating.')

class bird(animal):
    def sing(self):
        print('Brid is singing...')

    def eat(self):
        print('Brid id eating.')

class dog(animal):
    def eat(self):
        print('Dog is eating.')

a = animal()
# a.sing() 是错的

b = bird()
b.sing()

d = dog()
d.eat()