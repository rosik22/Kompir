#!/usr/bin/env python
import socket
import datetime

now = datetime.datetime.now()
s = socket.socket(socket.AF_INET)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
host = '127.0.0.1'
port = 1234

s.bind((host,port))
s.listen()
while True:
    c, addr = s.accept()
    print("Connected with", addr)
    msg = "Now is: " + str(now.day) + "-" + str(now.month) + "-" + str(now.year) + "-" + str(now.hour) + ":" + str(now.minute) + ":" + str(now.second)
    c.send(bytes(msg,'utf-8'))
    c.close()