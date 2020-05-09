#!/usr/bn/env python

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

a = input()
b = input()
print(bisection(a,b,f1))
print(bisection(a,b,f2))