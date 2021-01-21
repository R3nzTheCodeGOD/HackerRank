#!/bin/python3
import math
import os
import random
import re
import sys

def aVeryBigSum(ar):
    toplam = 0
    for i in ar:
        toplam += i
    return toplam

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    ar_count = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = aVeryBigSum(ar)
    fptr.write(str(result) + '\n')
    fptr.close()