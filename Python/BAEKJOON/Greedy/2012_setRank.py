# 2012번 등수 매기기 (Greedy) 
# https://www.acmicpc.net/problem/2012

import sys
input = sys.stdin.readline
N = int(input())
data = []
for i in range(N):
    data.append(int(input()))

data.sort()
sum = 0
for i in range(N):
    sum += abs(i + 1 - data[i])

print(sum)