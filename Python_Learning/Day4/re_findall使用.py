import re

rs = re.findall('\d+', 'chuan13zhi24')
print(rs)

# flag参数的作用
rs = re.findall('a.bc', 'a\nbc', re.DOTALL)
rs = re.findall('a.bc', 'a\nbc', re.S)
print(rs)

# 分组的作用
rs = re.findall('a.+bc', 'a\nbc', re.DOTALL)
print(rs) # ['a\nbc']

rs = re.findall('a(.+)bc', 'a\nbc', re.DOTALL)
print(rs) # ['\n']