# 17298번 오큰수 (stack)
# https://www.acmicpc.net/problem/17298

import sys
from collections import deque

input = sys.stdin.readline
N = int(input())

data = list(map(int, input().split()))
ans = [-1] * N
stack = deque()
for i in range(N):
    while stack and stack[-1][1] < data[i]:
        ans[stack[-1][0]] = data[i]
        stack.pop()
    stack.append((i, data[i]))

print(*ans)