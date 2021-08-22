import socket

# 1. 创建客户端套接字对象
# 参数一：ipv4
# 参数二：选择协议（SOCK_STREAM==>tcp）
tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 2. 和服务端套接字建立连接
# 参数：元组（两个元素）
# 元素一：服务器IP（字符串）
# 元素二：服务器端口（数字）
tcp_client_socket.connect(('127.0.0.1', 8080))

# 3. 发送数据
tcp_client_socket.send('123'.encode())

# 4. 接收数据
# 参数：以字节为单位的接受数据的大小
recv_data = tcp_client_socket.recv(1024)
print(recv_data)

# 5. 关闭客户端套接字
tcp_client_socket.close()