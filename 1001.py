# -*- coding: utf-8 -*-
"""
Created on Wed Mar  8 15:34:02 2017

@author: John
"""

n = input()
n = int(n)
i = 0
while(n != 1):
    if n % 2 != 0:
        n = 3 * n + 1
    n /= 2
    i += 1
print(i)