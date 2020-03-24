#!/usr/bin/env python3
import sys

def palindrome(word):
    if len(word) == 1 or len(word) == 0:
        return True
    if word[0] != word[-1]:
        return False
    return palindrome(word[1:-1])

word = sys.argv[1]
print(palindrome(word))