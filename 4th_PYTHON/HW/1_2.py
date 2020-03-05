#!/usr/bin/env python3
import sys

first = sys.argv[1]
second = sys.argv[3]

if(sorted(first) == sorted(second)):
    print("True")
else:
    print("False")