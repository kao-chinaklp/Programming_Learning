num = input('请输入数字：')
print(num)
print(type(num))
print(f'输入给类型为{type(int(num))}')

str1 = '1'
str2 = '1.1'
str3 = '(1000, 2000, 3000)'
str4 = '[1000, 2000, 3000]'
print(type(eval(str1)))
print(type(eval(str2)))
print(type(eval(str3)))
print(type(eval(str4)))