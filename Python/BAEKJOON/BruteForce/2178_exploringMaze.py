# 2178번 미로 탐색 (BruteForce) 
# https://www.acmicpc.net/problem/2178

from collections import deque

N, M = map(int, input().split()) # y,x
board = []
for i in range(N):
    board.append(list(input()))

dy = [0, 1, 0, -1] # 동 남 서 북
dx = [1, 0, -1, 0]

dq = deque()
dq.append((0, 0, 1))

isVisited = [[False for _ in range(M)] for _ in range(N)]
isVisited[0][0] = True
while dq:
    y, x, cnt = dq.popleft()
    if y == N - 1 and x == M - 1:
        print(cnt)
        break

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= N or nx >= M or board[ny][nx] == '0':
            continue
        
        if not isVisited[ny][nx]:
            isVisited[ny][nx] = True
            dq.append((ny, nx, cnt + 1))
