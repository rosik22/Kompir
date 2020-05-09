#!/usr/bn/env python
import unittest

class checkBisection(unittest.TestCase):
    def test(self):
        k = bisection(1,2,f2)
        self.assertEqual(k,1.15,"Wrong answer for function 2")

    def test2(self):
        s = bisection(1,2,f1)
        self.assertEqual(s,1.68,"Wrong answer for function 1")

def f1(x):
    return pow(2.71828,x)- 2*x-2

def f2(x):
    return x*x*x+3*x-5

def bisection(a,b,f):
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
    while (b-a)>=0.001:
        c = (a+b)/2
        if f(c)*f(a) < 0:
            b = c
        elif f(c)*f(b) < 0:
            a = c
        if f(c) == 0.0 or (b-a)/2 < 0.001:
            k = c
            break
    
    return float("{:.2f}".format(k))

if __name__ == '__main__':
    unittest.main()