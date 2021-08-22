import requests

url = 'https://sam.huat.edu.cn:8443/selfservice/'

r = requests.get(url, verify=False)

print(r.content)