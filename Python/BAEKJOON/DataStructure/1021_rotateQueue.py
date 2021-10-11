# 1021번 회전하는큐 (deque) 
# https://www.acmicpc.net/problem/1021

import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
index = list(map(int, input().split()))
data = [i+1 for i in range(N)]
dq = deque(data)
ans = 0
for i in range(M):
    c = dq.index(index[i])
    l = len(dq)
    if c < l - c:
        dq.rotate(-c)
        ans += c
    else:
        dq.rotate(l - c)
        ans += l - c
    dq.popleft()

print(ans)