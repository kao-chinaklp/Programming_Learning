from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier, export_graphviz


# 获取数据集
iris = load_iris()

# 划分数据集
x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state=22)

# 决策树预评估
estimator = DecisionTreeClassifier(criterion='entropy')
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

# 可视化决策树
export_graphviz(estimator, out_file='iris_tree.dot', feature_names=iris.feature_names)