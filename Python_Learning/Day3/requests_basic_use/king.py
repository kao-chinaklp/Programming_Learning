import requests
import json


class King(object):
    def __init__(self, word):
        self.url = 'http://ifanyi.iciba.com/index.php?c=trans&m=fy&client=6&auth_user=key_ciba&sign=37218aa29f55fdcc'
        self.headers = {
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.62'
        }
        self.data = {
            'from': 'zh',
            'to': 'en',
            'q': word
        }
        tmp = 'UM_distinctid=17b1fdb119cd34-0dec2f7690ffdf-7e687969-1fa400-17b1fdb119d3d4; Authorization=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJwYXlsb2FkIjoie1widWlkXCI6MzUyMDMzNjIsXCJnZW5lcmF0ZVRpbWVcIjoxNjI4MzI3MDc3LFwiZXhwaXJlVGltZVwiOjE2Mjk1MzY2NzcsXCJ0dGxcIjoxMjA5NjAwLFwibG9naW5Tb3VyY2VcIjpcImRlZmF1bHRcIn0ifQ.td9wzCaHCjXfyMCcjumN1LN6D3e9Xr0EnwqAcPTCxt8; _ustat={"i":"35203362","n":"2751719998@qq.com","e":"2751719998@qq.com","s":{"u":true,"m":false,"e":true},"t":1628327077,"sid":"f8cfa4a0d692562dcec30662dd16bc7c"}'
        cookie_list = tmp.split('; ')
        self.cookies = {cookie.split('=')[0]: cookie.split('=')[-1] for cookie in cookie_list}

    def get_data(self):
        # 使用post发送post请求，data为请求体的字典
        r = requests.post(self.url, headers=self.headers, data=self.data, cookies=self.cookies)
        return r.content

    def parse_data(self, data):
        # loads方法将json转化成字典
        dict_data = json.loads(data)

        print(dict_data)

    def run(self):
        # 编写爬虫逻辑

        # url
        # headers
        # data字典
        # 发送请求获取响应
        r = self.get_data()
        print(r)

        # 数据解析
        self.parse_data(r)


if __name__ == '__main__':
    word = input('请输入要翻译的单词或句子：')
    king = King(word)
    king.run()
