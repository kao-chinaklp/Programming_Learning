import requests

url = 'https://twitter.com'

proxies = {
    'http': '127.0.0.1:4780'
}

r = requests.get(url, proxies=proxies)

r.encoding = 'utf-8'

with open('tw.html', 'wb')as f:
    f.write(r.content)