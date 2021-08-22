from bs4 import BeautifulSoup
import requests

url = 'https://xihale.top'

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67'
}

proxies = {
    'http': "127.0.0.1:4780"
}

r = requests.get(url, headers=headers, proxies=proxies)

r.encoding = 'utf-8'

soup = BeautifulSoup(r.content.decode(), 'lxml')

title = soup.find('title')
print(title)

a = soup.find('a')
print(a)

# 查找所有a标签
# a_s = soup.find_all('a')
# print(a_s)

# 根据属性进行查找

# 1、通过命名参数来指定

A1 = soup.find(id='link1')
print(A1)

# 2、使用attrs来指定属性字典，进行查找
A2 = soup.find(attrs={'id': 'link2'})
print(A2)

# 3、根据文本内容来指定
text = soup.find(text='xihale')
print(text)

# Tag对象
print('标签名', type(a.name))
print('标签所有属性', type(a.attrs))
print('标签文本内容', type(a.text))