list1 = [1, 2, 3]

i = 0
while i < len(list1):
    print(list1[i], end=' ')
    i += 1

for i in list1:
    print(list1[i - 1], end='  ')