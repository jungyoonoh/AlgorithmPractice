# 14425번 문자열 집합 (set) 
# https://www.acmicpc.net/problem/14425

import sys

input = sys.stdin.readline

N, M = map(int, input().split())

pool = set()

for i in range(N):
    pool.add(input().strip())

ans = 0
for i in range(M):
    data = input().strip()
    if data in pool:
        ans += 1

print(ans)