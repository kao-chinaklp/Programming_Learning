import requests
from requests import utils

url = 'https://www.baidu.com'

r = requests.get(url)

print(r.cookies)

dict_cookies = requests.utils.dict_from_cookiejar(r.cookies)
print(dict_cookies)

jar_cookie = requests.utils.cookiejar_from_dict(dict_cookies)
print(jar_cookie)