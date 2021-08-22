import pymysql

# 1 建立连接
conn = pymysql.connect(host='localhost', port=3306, user='root', password='mima123', database='python1', charset='utf8')

# 2 创建游标 游标可以记录读取数据的个数
cur = conn.cursor()

# 3 执行sql
name = input('请输入要查询的物品名称：')
sql = "select * from class where name=%s;"
cur.execute(sql, [name])

# 4 获取数据
data = cur.fetchall()
for i in data:
    print(i)

# 如果要修改，就要提交请求
conn.commit()

# 5 关闭
cur.close()
conn.close()