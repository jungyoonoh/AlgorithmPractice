# 10026번 적록색약 (BruteForce) 
# https://www.acmicpc.net/problem/10026

import sys
from collections import defaultdict
from enum import Enum
input = sys.stdin.readline
sys.setrecursionlimit(10**4 + 1)

class color(Enum):
    RED = 0
    GREEN = 1
    BLUE = 2

N = int(input())

dy = [0, 1, 0, -1] # 동 남 서 북
dx = [1, 0, -1, 0] 

grid = [list(input().rstrip()) for _ in range(N)]
board = [[0 for _ in range(N)] for _ in range(N)]

def search(board, y, x, color, isVisited):
    isVisited[y][x] = True
    if board[y][x] == 0:
        board[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= N or nx < 0 or nx >= N:
            continue
        if not isVisited[ny][nx] and color == board[ny][nx]:
            search(board, ny, nx, color, isVisited)


ans = []
for i in range(N):
    for j in range(N):
        if grid[i][j] == 'G':
            board[i][j] = color.GREEN.value
        elif grid[i][j] == 'B':
            board[i][j] = color.BLUE.value

d = defaultdict(int)
isVisited = [[False for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if not isVisited[i][j]:
            search(board, i, j, board[i][j], isVisited)
            d[board[i][j]] += 1

ans.append(sum(d.values()))

d = defaultdict(int)
isVisited = [[False for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if not isVisited[i][j]:
            search(board, i, j, board[i][j], isVisited)
            d[board[i][j]] += 1

ans.append(sum(d.values()))
print(*ans)