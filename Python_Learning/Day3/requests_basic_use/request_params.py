import requests

# url = 'https://www.baidu.com/s?wd=python'
#
# headers = {
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (XHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.62'
# }
#
# r = requests.get(url, headers=headers)
#
# with open('baidu.html', 'wb')as f:
#     f.write(r.content)

url = 'https://www.baidu.com/s?'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (XHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.62'
}

# 构建参数字典
data = {
    'wd': 'python'
}

r = requests.get(url, headers=headers, params=data)

print(r.url)
with open('baidu1.html', 'wb')as f:
    f.write(r.content)