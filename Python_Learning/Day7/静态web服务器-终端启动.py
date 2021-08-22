import socket
import multiprocessing
import sys

class WebServer:
    def __init__(self, port=23340):
        # 创建socket
        self.tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # 端口复用
        self.tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)

        self.tcp_server_socket.bind(('127.0.0.1', port))

        # 设置监听
        self.tcp_server_socket.listen(128)

    @staticmethod
    def handler_client_request(client_socket):
        """用来处理浏览器请求"""
        # 接收数据
        recv_data = client_socket.recv(1024)
        if len(recv_data) == 0:
            return
        print(recv_data.decode())

        # 对请求报文进行切割
        path_list = recv_data.decode().split(' ')

        # 请求资源路径
        request_path = path_list[1]

        # 设置主页
        if request_path == '/':
            request_path = '/index.html'

        f_data = ''
        #异常捕获
        try:
            # 打开资源文件
            f = open('./' + request_path, 'rb')
            f_data = f.read()
            f.close()

            # 响应行
            response_line = 'HTTP/1.1 200 ok\r\n'
            response_header = 'Server:py1.0\r\n'
            response_body = f_data

            response_data = (response_line + response_header + '\r\n').encode() + response_body
        except Exception as e:
            print(e)
            response_line = 'HTTP/1.1 404 NOT FOUND\r\n'
            response_header = 'Server:py1.0\r\n'
            response_body = '<h1>404 not found</h1>'

            response_data = (response_line + response_header + '\r\n').encode() + response_body.encode()
        #发送数据
        client_socket.send(response_data)
        client_socket.close()

    def start(self):
        """控制整个服务器流程的函数"""
        while True:
            # 接受连接请求
            client_socket, client_addr = self.tcp_server_socket.accept()

            # 处理请求函数
            sub_process = multiprocessing.Process(target=self.handler_client_request, args=(client_socket,))
            sub_process.start()

if __name__ == '__main__':
    # 获取动态端口
    if len(sys.argv) != 2:
        print('格式错误'.encode())
        exit()
    else:
        port = sys.argv[1]

        web = WebServer(int(port))
        web.start()