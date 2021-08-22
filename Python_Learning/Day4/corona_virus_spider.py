import re
import json
import requests
from bs4 import BeautifulSoup

# 1、发送请求，获取疫情首页
headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67'
}
r = requests.get('http://ncov.dxy.cn/ncovh5/view/pneumonia', headers=headers)
home_page = r.content.decode()

# 2、从疫情首页，获取近一日各国疫情数据
soup = BeautifulSoup(home_page, 'lxml')
script = soup.find(id='getAreaStat')
text = script.string

# 3、从疫情数据中，获取json字符串
json_str = re.findall(r'\[.+\]', text)[0]

# 4、把json格式的字符串转化为python类型
last_day_corona_virus = json.loads(json_str)

# 5、以json格式保存，最近一日各国疫情数据
with open('data/last_day_corona_virus.json', 'wb')as fp:
    fp.write(json.dumps(last_day_corona_virus, ensure_ascii=False).encode())
