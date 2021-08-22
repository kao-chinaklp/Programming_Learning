import pickle

class people:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def sayhi(self):
        print("hi")

# p1 = people('jack', 30)
# f = open('p1', 'wb')
# pickle.dump(p1, f)
#
# f.close()
#

f = open('p1', 'rb')
p2 = pickle.load(f)
f.close()

print(p2)
p2.sayhi()