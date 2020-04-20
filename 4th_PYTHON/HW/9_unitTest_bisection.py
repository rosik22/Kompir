#!/usr/bin/env python3
import unittest

def f(x):
    return pow(2.71828,x)- 2*x-2

def bisection(a,b):
    try:
        a = float(a)
        b = float(b)
    except ValueError:
        print("One or both are not numbers")
        return 0
    try:
        if f(a)*f(b) >= 0:
            raise
    except:
        print("The interval of a and b is not valid")
        return 0

    k = 0
    while((b-a)>0.001):
        c = (a+b)/2
        if f(c) == 0 or (b-a)/2 < 0.001:
            k = c
            break
        if f(c)*f(a) >= 0:
            a = c
        elif f(c)*f(b) >= 0:
            b = c
    s = TestBisection()
    s.runTest(c)

    return k

class TestBisection(unittest.TestCase):
    def runTest(self,x):
        self.assertEqual(f(x),0,"Failed")

a = input()
b = input()
print(bisection(a,b))