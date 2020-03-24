#!/usr/bin/env python3
import sys

def binary_search(list1_1, beg, end, num):
    if end >= beg:
        mid = (beg + end)//2
        if num == list1_1[mid]:
            return "found at " + str(mid)
        if num < list1_1[mid]:
            return binary_search(list1_1, beg, mid - 1, num)
        else:
            return binary_search(list1_1, mid + 1, end, num)
    else:
        return "not found"

list1 = [30, 40, 50, 52, 56, 62, 70, 91, 100, 131, 
132, 166, 170, 195, 202, 205, 212, 248, 249, 256, 
263, 272, 288, 289, 290, 296, 332, 345, 352, 364, 
380, 390, 407, 412, 429, 430, 438, 444, 486, 493, 
497, 499, 510, 513, 514, 519, 521, 521, 535, 546, 
552, 554, 556, 570, 584, 638, 640, 655, 655, 657, 
692, 692, 711, 713, 731, 739, 740, 842, 858, 885, 
887, 888, 893, 898, 900, 903, 908, 909, 959, 988]

num = int(sys.argv[1])
print(binary_search(list1, 0, len(list1)-1,num))