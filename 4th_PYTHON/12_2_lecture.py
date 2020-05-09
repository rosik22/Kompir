#!/usr/bin/env python3
import socketserver

class RequestHandler(socketserver.StreamRequestHandler):
    def handle(self):
        l = True
        while l:
            l = self.rfile.readline().strip()
            if l:
                self.wfile.write(l[::-1]+'\n')

host = '127.0.0.1'
port = 3456
server = socketserver.ThreadingTCPServer((host,port),RequestHandler)
server.serve_forever()