#!/usr/bin/env python3
import sys

key = sys.argv[len(sys.argv)-1]

txt = []
for i in range(1,len(sys.argv) - 1):
    txt += sys.argv[i]

cipher = "" 
for i in range(len(txt)):
    char = txt[i]
    if char.isupper(): 
        cipher += chr((ord(char) + int(key)-65) % 26 + 65)
    else: 
        cipher += chr((ord(char) + int(key)-97) % 26 + 97)

print(cipher)