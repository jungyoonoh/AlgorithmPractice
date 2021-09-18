# 미로 탈출

from collections import deque

N, M = map(int, input().split()) # 세로, 가로
board = [list(map(int, input())) for _ in range(N)]
cost = [[1 for _ in range(M)] for _ in range(N)]
dx = [1, 0, -1, 0] # 동 남 서 북
dy = [0, 1, 0, -1]
print(board)
queue = deque()
queue.append((0,0))
while queue:
    y, x = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= M or ny >= N: # 맵 밖
            continue
        if board[ny][nx] == 0: # 괴물
            continue
        if board[ny][nx] == 1 and cost[ny][nx] == 1:
            cost[ny][nx] = cost[y][x] + 1 if cost[ny][nx] == 1 else min(cost[y][x] + 1, cost[ny][nx]) 
            queue.append((ny, nx))

print(cost[N-1][M-1])