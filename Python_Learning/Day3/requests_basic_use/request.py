import requests

url = "http://www.baidu.com"

r = requests.get(url)

# print(len(r.content.decode()))
# print(r.content.decode())

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (XHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.62'
}

# 发送带请求头字典
r1 = requests.get(url, headers=headers)

print(len(r1.content.decode()))
print(r1.content.decode())
