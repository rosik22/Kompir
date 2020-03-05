#!/usr/bin/env python3
import sys

check = False
for i in range(1, len(sys.argv) - 1):
    for j in range(i+1, len(sys.argv)):
        if sys.argv[i] == sys.argv[j]:
            check = True

print(check)