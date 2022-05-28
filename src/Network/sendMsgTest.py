import socket

while True:
    n = input("Type and press enter to send: ")
    byte_message = bytes(n, "utf-8")
    opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    opened_socket.sendto(byte_message, ("127.0.0.1", 7258))
