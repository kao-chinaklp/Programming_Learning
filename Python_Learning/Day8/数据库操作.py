import pymysql

# 1 建立连接
conn = pymysql.connect(host='localhost', port=3306, user='root', password='mima123', database='python1', charset='utf8')

# 2 创建游标 游标可以记录读取数据的个数
cur = conn.cursor()

# 3 执行sql
sql = 'select * from class;'
cur.execute(sql)

# 4 获取数据
data = cur.fetchone()
print(data)
data = cur.fetchall()
print(data) # 元组类型的 元组中的每一个元素都是一个数据库中的数据

# 5 关闭
cur.close()
conn.close()