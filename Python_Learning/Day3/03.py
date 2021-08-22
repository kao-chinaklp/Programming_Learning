class student:
    cout = 0

    def __init__(self, name):
        self.name = name


print(student.cout)

s1 = student(name='a')
print(s1.cout)
print(s1.name)

s1.name = 'B'
s1.count = 1
print(s1.name)
print(s1.cout)
print(student.cout)

student.count = 2
print(student.cout)
print(s1.count)

s2 = student(name='x')

print(s2.count)