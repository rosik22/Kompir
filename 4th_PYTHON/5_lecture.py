#!/usr/bin/env python3

#check how docstring works
def checkDoc(width, heigth):
    'something somth haha'
    return width/heigth

print(checkDoc(8,4))
print(checkDoc.__doc__)

#keep changes only for the function
def change_param(param):
    param[0] = "huehue"

p = ["tralala","ulala"]
change_param(p[:])
print(p)

#function creating tuples
def make_tuple(*param):
    print(param)

make_tuple("one","two")

#make dictionary
def make_dict(**param):
    print(param)

make_dict(x=1,y=2,z=3)

#call a global var with the same name as the local var
def shadow_var():
    name = "Ivanov"
    print(name)
    print(globals()['name'])

name = "Petrov"
shadow_var()

#calculat factorial
def fact(num):
    if num == 1:
        return num
    else:
        return num*fact(num-1)

print(fact(4))

#lambda hidden fuction
a = lambda x,y,z: x+y+z
print(a(2,3,4))

