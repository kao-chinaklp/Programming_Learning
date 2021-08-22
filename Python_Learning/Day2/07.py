list1 = ['tom', 'lili', 'rose']

#判断数据是否在列表
print('tom' in list1)
print('toms' not in list1)

#追加数据时如果数据是个序列，追加整个序列
list1.append('xiaoming')
list1.append([11, 12])
print(list1)

#逐一添加数据
list1.extend('xiao')
print(list1)

#指定位置添加数据
list1.insert(1, 'aaa')
print(list1)

#删除数据
#del(list1)
del(list1[1])
print(list1)

#删除指定数据，若不指定则删除最后一个
list1.pop()
print(list1)

#清空
list1.remove('rose')
print(list1)

#清空
list1.clear()
print(list1)