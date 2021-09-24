# 11651번 좌표 정렬하기 2 (Sort) 
# https://www.acmicpc.net/problem/11651

import sys

input = sys.stdin.readline
N = int(input())
data = []

for i in range(N):
    (x, y) = tuple(map(int, input().strip().split()))
    data.append((x,y))

data.sort()
data = sorted(data, key=lambda obj:obj[1])

for i in range(N):
    print(data[i][0], data[i][1])