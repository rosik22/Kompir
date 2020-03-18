#!/usr/bin/env python3
import sys

letter = sys.argv[len(sys.argv)-1]
d={1:'a',2:'b',3:'c',4:'a',5:'d',6:'e',7:'a',8:'b'}

answer = []
for key,value in d.items():
    if value == letter:
        answer.append(key)

print(answer)