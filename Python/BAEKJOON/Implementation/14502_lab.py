# 14502번 연구소 (Implementation) 
# https://www.acmicpc.net/problem/14502

from collections import deque
import itertools

def spread(board):
    queue = deque(virus)

    isVisited = [[False for _ in range(M)] for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if board[i][j] != 0:
                isVisited[i][j] = True
    reset = []
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                continue
            if not isVisited[ny][nx]:
                isVisited[ny][nx] = True
                queue.append((ny, nx))
                board[ny][nx] = 2
                reset.append((ny, nx))

    # print(queue)
    cnt = 0
    for i in range(len(board)):
        cnt += board[i].count(0)

    for y, x in reset:
        board[y][x] = 0

    return cnt


N, M = map(int, input().split())

dy = [0, 1, 0, -1] # 동 남 서 북
dx = [1, 0, -1, 0]

board = [list(map(int, input().split())) for _ in range(N)]

virus = []
canSetupWall = []
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            canSetupWall.append((i, j))
        if board[i][j] == 2:
            virus.append((i, j))

comb = list(itertools.combinations(canSetupWall, 3))
ans = 0
for coords in comb:
    for i in range(3):
        y, x = coords[i][0], coords[i][1]
        board[y][x] = 1

    ans = max(ans, spread(board))

    for i in range(3):
        y, x = coords[i][0], coords[i][1]
        board[y][x] = 0

print(ans)