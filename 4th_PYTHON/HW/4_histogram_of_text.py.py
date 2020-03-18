#!/usr/bin/env python3
import sys

letters = ''.join(sys.argv[1:])
d = {}
for i in letters:
    d[i] = d.get(i,0) + 1
answer = list(d.items())
print(answer)