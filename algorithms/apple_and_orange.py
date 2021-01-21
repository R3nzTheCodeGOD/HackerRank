#!/bin/python3
import math
import os
import random
import re
import sys

def countApplesAndOranges(s, t, a, b, apples, oranges):
    fallenapple = 0
    fallenorange = 0
    for apple in range(len(apples)):
        apples[apple] += a
    for orange in range(len(oranges)):
        oranges[orange] += b
    for i in range(len(apples)):
        if apples[i] >= s and apples[i] <= t:
            fallenapple += 1
    for b in range(len(oranges)):
        if oranges[b] <= t and oranges[b] >= s:
            fallenorange += 1
    print(fallenapple)
    print(fallenorange)

if __name__ == '__main__':
    st = input().split()
    s = int(st[0])
    t = int(st[1])
    ab = input().split()
    a = int(ab[0])
    b = int(ab[1])
    mn = input().split()
    m = int(mn[0])
    n = int(mn[1])
    apples = list(map(int, input().rstrip().split()))
    oranges = list(map(int, input().rstrip().split()))
    countApplesAndOranges(s, t, a, b, apples, oranges)