#!/usr/bin/env python3

x = 0
sum = 0
multi = 1
for x in range(1,11):
    multi *= x
    sum += 1/x
print(multi)
print(sum) 