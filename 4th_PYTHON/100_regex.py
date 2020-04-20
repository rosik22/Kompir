#!/usr/bin/env python3
import re

str = input()
phoneNumRegex = re.compile(r'\d{3}-\d{3}-\d{4}')
findNum = phoneNumRegex.search(str)
print("Found number: " + findNum.group())