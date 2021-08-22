from jsonpath import jsonpath
import json

data = {'key1': {'key2': {'key3': {'key4': {'key5': {'key6': 'python'}}}}}}

# jsonpath的结果为列表，获得数据需要索引
print(jsonpath(data, '$..key1.key2.key3.key4.key5.key6')[0])
print(jsonpath(data, '$..key6')[0])