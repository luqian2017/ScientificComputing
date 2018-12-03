# -*- coding: utf-8 -*-
"""
Created on Sun Dec  2 23:07:19 2018

@author: 

Reference:
1) https://stackoverflow.com/questions/45195059/efficient-mersenne-prime-generator-in-python
2) https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
3) https://zh.wikipedia.org/wiki/%E5%8D%A2%E5%8D%A1%E6%96%AF-%E8%8E%B1%E9%BB%98%E6%A3%80%E9%AA%8C%E6%B3%95
"""

def lucas_lehmer(p):
    s = 4
    m = (1 << p) - 1
    for _ in range(p - 2):
        s = ((s * s) - 2) % m
    return s == 0

def is_prime(number):
    if number & 0x1 == 0:
        return False

    i = 3
    while i * i <= number:
        if number % i == 0:
            return False
        i += 2

    return True

print("M 1 = 3")

for i in range(3, 5000, 2):  # generate up to M20, found in 1961
    if is_prime(i) and lucas_lehmer(i):
        print("M",i," = ", (1 << i) - 1);