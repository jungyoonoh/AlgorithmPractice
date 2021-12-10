# 2667번 단지번호붙이기 (BruteForce) 
# https://www.acmicpc.net/problem/2667

from collections import deque

def labeling(y, x):
    dq = deque()
    dq.append((y, x))
    M = 1
    isVisited[y][x] = True
    while dq:
        y, x = dq.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny < 0 or nx < 0 or ny >= N or nx >= N or town[ny][nx] == '0':
                continue
            
            if not isVisited[ny][nx]:
                isVisited[ny][nx] = True
                dq.append((ny, nx))
                M += 1
    
    return M
    
N = int(input())

town = []
for i in range(N):
    town.append(list(input()))
    
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

isVisited = [[False for _ in range(N)] for _ in range(N)]
ans = []
for i in range(N):
    for j in range(N):
        if town[i][j] == '1' and not isVisited[i][j]:
            ans.append(labeling(i, j))
            
print(len(ans))
ans.sort()
for i in ans:
    print(i)