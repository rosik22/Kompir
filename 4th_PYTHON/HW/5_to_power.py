#!/usr/bin/env python3
import sys

def toPower(num, power):
    if power == 0:
        return 1
    elif power >= 1:
        return num * toPower(num, power-1)

num = int(sys.argv[1])
power = int(sys.argv[2])

print(toPower(num,power))