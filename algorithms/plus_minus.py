#!/bin/python3
import math
import os
import random
import re
import sys

def plusMinus(arr):
    positive = 0
    negative = 0
    zero = 0
    for i in arr:
        if i < 0:
            negative += 1
        elif i > 0:
            positive += 1
        else:
            zero += 1
    print(float(positive/len(arr)))
    print(float(negative/len(arr)))
    print(float(zero/len(arr)))

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    plusMinus(arr)