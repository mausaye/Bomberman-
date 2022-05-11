import socket

byte_message = bytes("Hello, Tammy! Testing with a longer message.", "utf-8")
opened_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
opened_socket.sendto(byte_message, ("127.0.0.1", 7258))
