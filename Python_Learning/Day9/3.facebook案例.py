import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier

#获取数据
data = pd.read_csv('./FBlocation/train.csv')

# 数据处理
data = data.query('x < 2.5 & x > 2.0 & y < 1.5 & y > 1.0')
time_value = pd.to_datetime(data['time'], unit='s')
date = pd.DatetimeIndex(time_value)
data['day'] = date.day
data['weekday'] = date.weekday
data['hour'] = date.hour

# 过滤签到次数少的地方
place_count = data.groupby('place_id').count()['row_id']
data_final = data[data['place_id'].isin(place_count[place_count > 3].index.values)]

# 简述特征值和目标值
x = data_final[['x', 'y', 'accuracy', 'day', 'weekday', 'hour']]
y = data_final['place_id']

# 数据集划分
x_train, x_test, y_train, y_test = train_test_split(x, y)
estimator = KNeighborsClassifier()

# 特征工程：标准化
transfer = StandardScaler()
x_train = transfer.fit_transform(x_train)
x_test = transfer.transform(x_test)

# knn算法评估
#加入网格搜索与交叉验证
# 参数准备
param_dict = {'n_neighbors': [3, 5, 7, 9]}
estimator = GridSearchCV(estimator, param_grid=param_dict, cv=10)
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