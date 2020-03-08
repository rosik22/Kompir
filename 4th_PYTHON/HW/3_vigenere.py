#!/usr/bin/env python3
txt = input("Enter sentence: ")
key = input("Enter key: ")

cipher = []
key = list(key)
for i in range(len(txt) - len(key)): 
    key.append(key[i % len(key)])

for i in range(len(txt)):
    if txt[i].isupper():
        x = (ord(txt[i]) + ord(key[i])) % 26 + 65
    else:
        x = (ord(txt[i]) - 97 + ord(key[i]) - 97) % 26 + 97
    cipher.append(chr(x))
answer = "".join(cipher)

print(answer)