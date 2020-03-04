#!/usr/bin/env python3

list = (['b','a'])
for x in list[0:1]:
    if(list[x] < list[x+1]):
        x = 1
    else: 
        x = 0
if x == 1:
    print("true")
else:
    print("false")