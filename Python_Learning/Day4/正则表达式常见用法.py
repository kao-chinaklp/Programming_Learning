import re

# 字符匹配
rs = re.findall('abc', 'abc')
rs = re.findall('a.c', 'a\nc') # 除了换行符
rs = re.findall('a.c', 'a.c')
rs = re.findall('a\.c', 'a.c')
rs = re.findall('a[bc]d', 'abd')

# 预定义字符集
rs = re.findall('\d', '123') # 匹配数字
rs = re.findall('\w', '123') # 匹配字母、数字下划线、中文

# 数量词
rs = re.findall('a\d*', 'a123') # 允许出现零次
rs = re.findall('a\d+', 'a') # 不允许出现零次
rs = re.findall('a\d?', 'a123') # 出现1次
rs = re.findall('a\d{2}', 'a123') # 出现2次
print(rs)