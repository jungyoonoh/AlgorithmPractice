# 11501번 주식 (Greedy) 
# https://www.acmicpc.net/problem/11501

import sys
TC = int(input())

for _ in range(TC):
    ans = 0
    N = int(input())
    data = list(map(int, sys.stdin.readline().split()))
    M = data[-1]
    for i in range(N - 2, -1, -1): # N-2 ~ 0까지 -1씩
        if data[i] > M:
            M = data[i]
        else:
            ans += M - data[i]
    print(ans)