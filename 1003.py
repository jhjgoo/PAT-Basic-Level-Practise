# -*- coding: utf-8 -*-
"""
Created on Wed Mar  8 16:31:10 2017

@author: John
"""
import re

n = input()
pattern = re.compile(r'(^A*)P{1}(A+)T{1}(A*$)')
for i in range(int(n)):
    sample = input()
    match = pattern.match(sample)
    if(match):
        head = match.group(1)
        middle = match.group(2)
        tail = match.group(3)
        if (len(head) * len(middle) == len(tail)):
            print('YES')
            continue
    print('NO')