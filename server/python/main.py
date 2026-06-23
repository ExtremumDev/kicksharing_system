import socket as sock

s = sock.socket(sock.AF_INET, sock.SOCK_DGRAM, sock.IPPROTO_UDP)

s.bind(("0.0.0.0", 6500))


while True:
    get_bytes = s.recv(12)
    print(get_bytes)
