from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import GridSearchCV

def knn_iris():
    """
    用knn算法对鸢尾花进行分类
    :return:
    """
    # 获取数据
    iris = load_iris()

    # 划分数据集
    x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state=6)

    # 特征工程：标准化
    transfer = StandardScaler()
    x_train = transfer.fit_transform(x_train)
    x_test = transfer.transform(x_test)

    # knn算法评估
    estimator = KNeighborsClassifier(n_neighbors=3)
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

def knn_iris_gscv():
    """
    用knn算法对鸢尾花进行分类，添加网格搜索和交叉验证
    :return:
    """
    # 获取数据
    iris = load_iris()

    # 划分数据集
    x_train, x_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state=6)

    # 特征工程：标准化
    transfer = StandardScaler()
    x_train = transfer.fit_transform(x_train)
    x_test = transfer.transform(x_test)

    # knn算法评估
    estimator = KNeighborsClassifier()

    #加入网格搜索与交叉验证
    # 参数准备
    param_dict = {'n_neighbors': [1, 3, 5, 7, 9, 11]}
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

    print('最佳参数：\n', estimator.best_params_)
    print('最佳结果：\n', estimator.best_score_)
    print('最佳估计器：\n', estimator.best_estimator_)
    print('交叉验证结果：\n', estimator.cv_results_)

if __name__ == '__main__':
    # 用KNN算法对鸢尾花进行比对
    # knn_iris()
    # 用knn算法对鸢尾花进行分类，添加网格搜索和交叉验证
    knn_iris_gscv()