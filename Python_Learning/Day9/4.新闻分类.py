from sklearn.model_selection import train_test_split
from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB


# 获取数据
news = fetch_20newsgroups(subset='all')

# 划分数据集
x_train, x_test, y_train, y_test = train_test_split(news.data, news.target)

# 特征工程
# 文本特征抽取
transfer = TfidfVectorizer()
x_train = transfer.fit_transform(x_train)
x_test = transfer.transform(x_test)

# 朴素贝叶斯预估数据
estimator = MultinomialNB()
estimator.fit(x_train, y_train)

# 模型评估
# way1:
# 直接比对测试纸和真实值
y_predict = estimator.predict(x_test)
print('y_predict:\n', y_predict)
print('直接比对真实值和测试值：\n', y_test == y_predict)

# way2:
# 计算准确率
score = estimator.score(x_test, y_test)
print('准确率为：\n', score)