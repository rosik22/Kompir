#!/usr/bin/env python3

a = int(input())
b = int(input())
c = int(input())

if a > 0:
    d = b**2-4*a*c
    if d > 0:
        print("x1 and x2 exist")
    else:
        print("x1 and x2 don't exist")
else:
    if b > 0:
        x = -c/b
        print(x)
    else:
        print("Weird")

