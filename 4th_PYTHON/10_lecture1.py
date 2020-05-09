#!/usr/bin/env python3
import sys


file = open('t.txt','a')

file.write('I am doing fine\nBuy buy')
file.close()

f = open('t.txt','r')
for line in f:
    print(line)

f.close()