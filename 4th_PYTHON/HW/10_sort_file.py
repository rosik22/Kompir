#!/usr/bin/ebv python3
from sys import argv

script,file1,file2 = argv

readFile = open(file1, 'r+')
writeFile = open(file2, 'w+')

try:
    lines = sorted(readFile.readlines())
    for line in lines:
        writeFile.write(line)
finally:
    readFile.close()
    writeFile.close()