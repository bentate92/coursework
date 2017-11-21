# Name: Benjamin Tate
# Date: 4/9/2017
# Course: CS 325 -- Section 400
# Assignment: HW 1, Problem 5

import sys
from random import randint
import time

def RandomArray(n):
    l = []

    for i in range(0, n):
        l.append(randint(0, 1000))

    return l

#Adapted from https://en.wikipedia.org/wiki/Insertion_sort
def InsertionSort(l):
    for i in range(1,len(l)):
        x = l[i]
        j = i - 1
        
        while (j >= 0) and (l[j] > x):
            l[j+1] = l[j]
            j = j - 1

        l[j+1] = x

    return l

#Adapted from https://pythonandr.com/2015/07/05/the-merge-sort-python-code/
def Merge(a, b):
    l = []

    while (len(a) != 0) and (len(b) != 0):
        if a[0] < b[0]:
            l.append(a[0])
            a.remove(a[0])
        else:
            l.append(b[0])
            b.remove(b[0])

    if len(a) == 0:
        l += b
    else:
        l += a

    return l

#Adapted from https://pythonandr.com/2015/07/05/the-merge-sort-python-code/
def MergeSort(l):
    if len(l) <= 1:
        return l
    else:
        mid = len(l) / 2
        left = MergeSort(l[:mid])
        right = MergeSort(l[mid:])

        return Merge(left, right)

def main():
    if len(sys.argv) != 2:
        print("Usage: hw1p5.py <n>")
        return
    
    n = int(sys.argv[1])
    
    l = RandomArray(n)

    start = time.time()
    merge = MergeSort(l)
    end = time.time()
    print("MergeSort executed in {} seconds.".format(end - start))
    
    start = time.time()
    insert = InsertionSort(l)
    end = time.time()
    print("InsertionSort executed in {} seconds.".format(end - start))

main()
