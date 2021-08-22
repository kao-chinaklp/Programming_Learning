import re
import requests
from bs4 import BeautifulSoup

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67'
}

r = requests.get('http://ncov.dxy.cn/ncovh5/view/pneumonia', headers=headers)

home_page = r.content.decode()
# print(home_page)

soup = BeautifulSoup(home_page, 'lxml')
script = soup.find(id='getAreaStat')
text = script.string
# print(text)

# 使用正则表达式，提取json字符串
json_str = re.findall(r'\[.+\]', text)[0]
print(json_str)