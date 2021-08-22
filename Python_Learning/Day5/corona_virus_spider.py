import re
import json
import requests
from bs4 import BeautifulSoup
from tqdm import tqdm


class CoronaVirusSpider(object):
    def __init__(self):
        self.home_url = 'http://ncov.dxy.cn/ncovh5/view/pneumonia'
        self.headers = {
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67'
        }

    # 1、发送请求，获取疫情首页
    def get_content_from_url(self, url):
        r = requests.get(url, headers=self.headers)
        return r.content.decode()

    # 2、从疫情首页，获取近一日各国疫情数据
    def parse_home_page(self, home_page):
        soup = BeautifulSoup(home_page, 'lxml')
        script = soup.find(id='getAreaStat')
        text = script.string
        # 3、从疫情数据中，获取json字符串
        json_str = re.findall(r'\[.+\]', text)[0]

        # 4、把json格式的字符串转化为python类型
        last_day_corona_virus = json.loads(json_str)
        return last_day_corona_virus

    # 5、以json格式保存，最近一日各国疫情数据
    def save(self, data, path):
        with open('data/last_day_corona_virus.json', 'wb')as fp:
            fp.write(json.dumps(data, ensure_ascii=False).encode())

    def crawl_last_day_corona_virus(self):
        """
        采集最近一天各国疫情信息
        :return:
        """
        # 1、发送请求，获取首页内容
        home_page = self.get_content_from_url(self.home_url)

        # 2、解析首页内容，获取最近一天的各国疫情数据
        last_data_corona_virus = self.parse_home_page(home_page)

        # 3、保存数据
        self.save(last_data_corona_virus, 'data/last_corona_virus.json')

    # 采集各国疫情数据
    def craml_corona_virus(self):
        # 1、加载各国疫情数据
        with open('data/last_day_corona_virus.json', 'r', encoding='UTF-8')as fp:
            last_day_corona_virus = json.load(fp)

        # 定义列表，用于存储疫情数据
        corona_virus = []

        # 2、遍历各国疫情数据，获取统计的url
        for country in tqdm(last_day_corona_virus, '采集各国疫情信息'):
            # 3、发送请求，获取从2020/01/23至今的json数据
            statistics_data_url = country['statisticsData']
            statistics_data_json_str = self.get_content_from_url(statistics_data_url)

            # 4、把json数据转为python类型，添加到列表中
            statistics_data = json.loads(statistics_data_json_str)['data']
            for one_day in statistics_data:
                one_day['provinceShortName'] = country['provinceShortName']
            corona_virus.extend(statistics_data)

            # 5、把列表以json格式保存
            self.save(corona_virus, 'data/corona_virus.json')

    def run(self):
        self.crawl_last_day_corona_virus()
        self.craml_corona_virus()

if __name__ == '__main__':
    spider = CoronaVirusSpider()
    spider.run()
