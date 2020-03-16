#!/usr/bin/env python3
import sys

cipher = []
txt = ""
for i in range (1, len(sys.argv) - 1):
    txt += sys.argv[i]

key = sys.argv[len(sys.argv)-1]
for i in range(len(txt) - len(key)): 
    key += key[i % len(key)]

for i in range(len(txt)):
    if txt[i].isupper():
        if key[i].isupper():
            x = (ord(txt[i]) + ord(key[i])) % 26 + 65
        else:
            x = (ord(txt[i]) - 65 + ord(key[i]) - 97) % 26 + 65
    else:
        if key[i].islower():
            x = (ord(txt[i]) - 97 + ord(key[i]) - 97) % 26 + 97
        else:
            x = (ord(txt[i]) - 97 + ord(key[i]) -65) % 26 + 97
    cipher += chr(x)
answer = "".join(cipher)

print(answer)