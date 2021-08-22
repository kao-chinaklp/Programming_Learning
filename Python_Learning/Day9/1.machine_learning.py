from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction import DictVectorizer
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn.preprocessing import MinMaxScaler, StandardScaler
from sklearn.feature_selection import VarianceThreshold
from sklearn.decomposition import PCA
from scipy.stats import pearsonr
import jieba
import pandas as pd


def datasets_demo():
    """
    skleaen的使用
    :return:
    """
    # 获取数据
    iris = load_iris()
    # print('鸢尾花数据集：\n', iris)
    print('查看数据集描述：', iris['DESCR'])
    print('查看特征名字：', iris.feature_names)
    print('查看特征值：', iris.data.shape)
    print('查看标签名：', iris.target_names)

    # 数据集划分
    x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.2 , random_state=22)
    print('训练集的特征值：', x_train, x_train.shape)

def dict_demo():
    """
    字典特征抽取
    :return:
    """
    data = [{'city': '北京', 'temperature': 100}, {'city': '上海', 'temperature': 50}, {'city': '深圳', 'temperature': 30}]

    # 实例化一个转换器类
    transfer = DictVectorizer(sparse=False)

    # 调用fit_transform()
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new)
    print('特征名字：', transfer.get_feature_names())

def count_demo():
    """
    文本特征收取
    :return:
    """
    data = ['Life is like like python', 'Life is long, i dislike python']
    # 实例化一个转换器类
    transfer = CountVectorizer()

    # 使用fit_trans
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new.toarray())
    print('特征名字：\n', transfer.get_feature_names())

def count_chinese_demo():
    """
    中文文本特征收取
    :return:
    """
    data = ['我爱中国', '我们中国实在是太棒了']
    # 实例化一个转换器类
    transfer = CountVectorizer()

    # 使用fit_trans
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new.toarray())
    print('特征名字：\n', transfer.get_feature_names())

def cut_word(text):
    """
    进行中文分词 我爱中国 -> 我 爱 中国
    :return:
    """
    return ' '.join(list(jieba.cut(text)))

def cout_chinese_demo2():
    """
    中文文本特征抽取，自动分词
    :return:
    """
    data = ['我爱中国', '我们中国实在是太棒了']
    data_new = []
    for sent in data:
        data_new.append(cut_word(sent))

    # 实力一个转换器类
    transfer = TfidfVectorizer()

    # 使用fit_trans
    data_new = transfer.fit_transform(data_new)
    print('data_new:\n', data_new.toarray())
    print('特征名字：\n', transfer.get_feature_names())

def tfidf_demo():
    """
    用tfidf方法进行文本特征抽取
    :return:
    """
    data = ['我爱中国', '我们中国实在是太棒了']
    data_new = []
    for sent in data:
        data_new.append(cut_word(sent))

    # 实力一个转换器类
    transfer = CountVectorizer()

    # 使用fit_trans
    data_new = transfer.fit_transform(data_new)
    print('data_new:\n', data_new.toarray())
    print('特征名字：\n', transfer.get_feature_names())

def minmax_demo():
    """
    归一化
    :return:
    """
    # 获取数据
    data = pd.read_csv('dating.txt')
    data = data.iloc[:, :3]

    # 实例化一个转化器类
    transfer = MinMaxScaler(feature_range=[2, 3])

    # 调用fit_transform()
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new)

def stand_demo():
    """
    归一化
    :return:
    """
    # 获取数据
    data = pd.read_csv('dating.txt')
    data = data.iloc[:, :3]

    # 实例化一个转化器类
    transfer = StandardScaler()

    # 调用fit_transform()
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new)

def variance_demo():
    """
    过滤低方差特征
    :return:
    """
    # 获取数据
    data = pd.read_csv('factor_returns.csv')
    data = data.iloc[:, 1:-2]

    # 实例化一个转换器类
    transfer = VarianceThreshold(threshold=5)

    # 调用fit_transform()
    data_new = transfer.fit_transform(data)

    # 计算某两个变量之间的相关系数
    r1 = pearsonr(data['pe_ratio'], data['pb_ratio'])
    print('相关系数：\n', r1)
    r2 = pearsonr(data['revenue'], data['total_expense'])
    print('revenue与total_expense之间的相关性：\n', r2)

def PCA_demo():
    """
    PCA降维
    :return:
    """
    data = [[2, 8, 4, 5], [6, 3, 0, 8], [5, 4, 9, 1]]

    # 实例化转换器类
    transfer = PCA(n_components=0.95)

    # 调用fit_transform()
    data_new = transfer.fit_transform(data)
    print('data_new:\n', data_new)

def instacart_pca_demo():
    # 获取数据
    order_products = pd.read_csv('./instacart/order_products__prior.csv')
    products = pd.read_csv('./instacart/products.csv')
    orders = pd.read_csv('./instacart/orders.csv')
    aisles = pd.read_csv('./instacart/aisles.csv')

    # 合并aisles和products
    tab1 = pd.merge(aisles, products, on=['aisle_id', 'aisle_id'])
    tab2 = pd.merge(tab1, order_products, on=['product_id', 'product_id'])
    tab3 = pd.merge(tab2, orders, on=['order_id', 'order_id'])

    # 找到user_id与aisle的关系
    table = pd.crosstab(tab3['user_id'], tab3['aisle'])

    # 实例化转换器类
    transfer = PCA(n_components=0.95)

    # 调用fit_transform()
    data_new = transfer.fit_transform(table)
    print('data_new:\n', data_new)

if __name__ == '__main__':
    # datasets_demo()
    # dict_demo()
    # count_demo()
    # count_chinese_demo()
    # cut_word('我爱中国')
    # cout_chinese_demo2()
    # tfidf_demo()
    # minmax_demo()
    # stand_demo()
    # variance_demo()
    # PCA_demo()
    instacart_pca_demo()