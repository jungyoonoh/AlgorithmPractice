# 1697번 숨바꼭질 (BruteForce) 
# https://www.acmicpc.net/problem/1697

from collections import deque

N, M = map(int, input().split())

size = 100001
board = [0] * size

dq = deque()
dq.append(N)

while dq:
    x = dq.popleft()
    if x == M:
        print(board[x])
        break
    for nx in (x-1, x+1, x*2):
        if nx < 0 or nx >= size or board[nx]:
            continue
        board[nx] = board[x] + 1
        dq.append(nx)