#!/usr/bin/env python3
txt = input("Enter sentence: ")
key = input("Enter key: ")

cipher = "" 
for i in range(len(txt)):
    char = txt[i]
    if char == ' ':
        cipher += " " 
    elif char.isupper(): 
        cipher += chr((ord(char) + int(key)-65) % 26 + 65)
    else: 
        cipher += chr((ord(char) + int(key)-97) % 26 + 97)

print(cipher)