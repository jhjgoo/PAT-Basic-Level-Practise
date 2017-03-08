# -*- coding: utf-8 -*-
"""
Created on Wed Mar  8 15:45:49 2017

@author: John
"""

str_in = input()
array = [int(n) for n in str_in]
sum = 0
for x in array:
    sum += x
pinyin = ['ling','yi','er','san','si','wu','liu','qi','ba','jiu']
str_out = str(sum)
for i in range(len(str_out)-1):
    print(pinyin[int(str_out[i])],end = " ")
print(pinyin[int(str_out[len(str_out)-1])])
        