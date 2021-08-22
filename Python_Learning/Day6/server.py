import socket

tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

tcp_server_socket.bind(('127.0.0.1', 8080))

tcp_server_socket.listen(123)

client_socket, client_addr = tcp_server_socket.accept()

client_data = client_socket.recv(1024)
client_data.decode()

client_socket.send('123'.encode())

client_socket.close()
tcp_server_socket.close()