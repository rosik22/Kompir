#!/usr/bin/env python3
from sys import argv

script,stemfile,word = argv
readStem = open(stemfile, 'r+')
stemDict = {}
for line in readStem:
    derivedWord, stemWord = line.strip().split(":")
    stemDict[derivedWord.strip()] = stemWord.strip()

readStem.close()
print(stemDict[word])