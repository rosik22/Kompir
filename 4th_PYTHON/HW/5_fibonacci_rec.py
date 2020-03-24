#!/usr/bin/env python3
import sys

cache = {}
cache[1] = 0
cache[2] = 1
def memory(num):
    if num not in cache:          
        cache[num] = fibonacci(num)

def fibonacci(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    if num-1 in cache.keys() and num-2 in cache.keys():
        return cache[num-1] + cache[num-2]
    else:
        memory(num-1)
        return fibonacci(num - 1) + fibonacci(num - 2)

begin = int(sys.argv[1])
end = int(sys.argv[2])

for i in range(begin, end+1):
    memory(i)

ans = list(cache.values())
print(ans[begin-1:])