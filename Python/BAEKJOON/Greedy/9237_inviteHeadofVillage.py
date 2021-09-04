# 9237번 이장님 초대 (Greedy) 
# https://www.acmicpc.net/problem/9237

import sys
N = int(input())

data = list(map(int, sys.stdin.readline().split()))
data.sort(reverse=True)

for i in range(2, len(data) + 2):
    data[i-2] += i

print(max(data))