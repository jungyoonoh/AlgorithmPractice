# 7576번 토마토 (BruteForce) 
# https://www.acmicpc.net/problem/7576

import sys
from collections import deque

input = sys.stdin.readline

dy = [-1, 0, 1, 0] # 위 오 아 왼
dx = [0, 1, 0, -1]

M, N = map(int, input().split()) # 가로, 세로
board = [list(map(int, input().split())) for _ in range(N)]
day = [[0 for _ in range(M)] for _ in range(N)]
isVisited = [[False for _ in range(M)] for _ in range(N)]
dq = deque()

for i in range(N):
    for j in range(M):
        if board[i][j] == 1:
            isVisited[i][j] = True
            dq.append((i, j))

day = 0
nextDay = deque()
while True:
    while dq:
        y, x = dq.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny < 0 or ny >= N or nx < 0 or nx >= M or isVisited[ny][nx] or board[ny][nx] == -1:
                continue
            isVisited[ny][nx] = True
            board[ny][nx] = 1
            nextDay.append((ny,nx))

    if not nextDay:
        break

    day += 1
    while nextDay:
        dq.append(nextDay.popleft())

flag = True
for i in range(N):
    if 0 in board[i]:
        flag = False
        break
if flag:
    print(day)
else: print(-1)