#!/bin/python3
import math
import os
import random
import re
import sys

def diagonalDifference(arr):
    soldiagonal = 0
    sagdiagonal = 0
    for i in range(0, len(arr)):
        soldiagonal += arr[i][i]
        sagdiagonal += arr[len(arr) - 1 - i][i]
    return(abs(soldiagonal - sagdiagonal))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input().strip())
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))
    result = diagonalDifference(arr)
    fptr.write(str(result) + '\n')
    fptr.close()