# 11652번 카드 (dict) 
# https://www.acmicpc.net/problem/11652

from collections import defaultdict
import sys

input = sys.stdin.readline

N = int(input())

dd = defaultdict(int)

for i in range(N):
    dd[int(input())] += 1

v = dd.values()
maxVal = max(v)
ans = []
for i in dd.keys():
    if maxVal == dd[i]:
        ans.append(i)

ans.sort()

print(ans[0])
