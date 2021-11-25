# 1427번 contact (String) 
# https://www.acmicpc.net/problem/1427

import re

T = int(input())

for i in range(T):
    s = input().strip()
    p = re.compile('(100+1+|01)+')
    if p.fullmatch(s):
        print("YES")
    else: print("NO")