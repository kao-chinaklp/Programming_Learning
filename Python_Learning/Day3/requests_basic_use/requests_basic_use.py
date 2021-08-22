import requests

url = 'http://www.baidu.com'

r = requests.get(url)

# r.encoding = 'utf-8'
#
# # str类型
# print(r.text)
#
# # 是存储的bytes类型的响应源码，可以进行decode操作
# print(r.content)
#
# print(r.content.decode())


# # 常见的响应对象参数和方法
# # 响应url
# print(r.url)
#
# # 状态码
# print(r.status_code)
#
# # 响应对应的请求头
# print(r.request.headers)
#
# #响应头
# print(r.headers)

#响应对应的cookie
# print(r.request._cookies)
#
# #响应cookie
# print(r.cookies)