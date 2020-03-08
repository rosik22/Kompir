#!/usr/bin/env python3
import string
#import maketrans in string
s = "string. With. Punctuation?"
out = s.translate(str.maketrans("","", string.punctuation))
print(out)
