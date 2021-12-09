# 1987번 알파벳 (BruteForce) 
# https://www.acmicpc.net/problem/1987

import sys

def bfs(y, x):
    global M
    
    q = set([(y, x, board[y][x])])
    
    while q:
        y, x, trace = q.pop()
              
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
        
            if ny < 0 or nx < 0 or ny >= R or nx >= C:
                continue
        
            if board[ny][nx] not in trace:
                q.add((ny, nx, trace + board[ny][nx]))
                M = max(M, len(trace) + 1)
                
M = 1
R, C = map(int, input().split())
input = sys.stdin.readline
board = [list(input().strip()) for _ in range(R)]
dy = [0, 1, 0, -1] # 동남서북
dx = [1, 0, -1, 0]
bfs(0, 0)
print(M)

# DFS로 풀면 시간초과 나서 BFS로 변경 -> 최단거리로 탐색해야