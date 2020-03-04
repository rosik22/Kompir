#!/usr/bin/env python3
import sys

check = True
for i in range(2,len(sys.argv)):
    if(sys.argv[i]<sys.argv[i-1]):
        check = False
        break

if check == True:
    print("sorted")
else:
    print("unsorted")