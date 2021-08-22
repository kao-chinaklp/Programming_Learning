f = open('test1.txt', mode='w', encoding='utf8')
"""
x 创建个新文件后写入
a 追加
w 重写
"""

f.write('line 1\n')

f.writelines(['line 2\n', 'line 3\n'])

f.write("第四行\n")

f.close()