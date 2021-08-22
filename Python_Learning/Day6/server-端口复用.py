import socket
import multiprocessing


def handler_client_request(client_socket):
    """处理客户端请求"""
    while True:
        client_data = client_socket.recv(1024)
        if len(client_data) == 0:
            print('客户端关闭了！')
            break

        client_data.decode()
        print(client_data)

        client_socket.send('123'.encode())

    client_socket.close()


def main():
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 端口复用设置
    tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)

    tcp_server_socket.bind(('192.168.2.7', 8080))

    tcp_server_socket.listen(123)

    while True:
        client_socket, client_addr = tcp_server_socket.accept()

        sub_process = multiprocessing.Process(target=handler_client_request, args=(client_socket,))
        sub_process.start()

    tcp_server_socket.close()

if __name__ == '__main__':
    main()