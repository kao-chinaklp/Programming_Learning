f = open('test1.txt', encoding='utf8')

# for line in f:
#     print(line,end='')

b = f.readlines()
f.seek(0)
a = f.readline()

print(b, type(b))
print(a, type(a))

f.close()