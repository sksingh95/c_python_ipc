import socket

HOST = "127.0.0.1"    #localhost address for loopback
PORT = 8889           #Port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello, world")
    data = s.recv(1024)
    
print("Received ", repr(data))