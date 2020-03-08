#!/usr/bin/env python3
import sys

arr = list()
sys.argv.sort()
arr.append(sys.argv[1])

for i in range(2, len(sys.argv)):
    if(sys.argv[i] != sys.argv[i-1]):
        arr.append(sys.argv[i])

arr = [int(i) for i in arr]
print(arr)