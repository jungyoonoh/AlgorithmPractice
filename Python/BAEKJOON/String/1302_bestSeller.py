# 1302번 베스트셀러 (String) 
# https://www.acmicpc.net/problem/1302

from collections import defaultdict
import sys

input = sys.stdin.readline

N = int(input())
dd = defaultdict(int)
for i in range(N):
    dd[input().strip()] += 1
    
sell = dd.keys()
ans = []
for i in sell:
    ans.append((i, dd[i]))
    
ans.sort(key=lambda x:(-x[1], x[0]))
print(ans[0][0])