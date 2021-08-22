mystr = 'hello world and incast and itheima and Python'

#重置字符串中的字串
#字符串.replace(目标字串, 替换字串, 替换次数)
str1 = mystr.replace('ans', 'he')
print(str1)

#字符串是不可变类型

#分割字符串，返回链表，丢失分割字符，分割n次
list1 = mystr.split('and', 2)
print(list1)

#合并字符串
mylist = ['aa', 'bb', 'cc']

str2 = '...'.join(mylist)
print(str2)