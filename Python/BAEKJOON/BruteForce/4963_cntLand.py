# 4963번 섬의 개수 (BruteForce) 
# https://www.acmicpc.net/problem/4963

from collections import deque

def search(board, y, x, h, w, isVisited):
    dq = deque()
    dq.append((y, x))
    total = 1
    while dq:
        nowY, nowX = dq.popleft()
        
        for i in range(8):
            ny = nowY + dy[i]
            nx = nowX + dx[i]
            
            if ny < 0 or nx < 0 or ny >= h or nx >= w or board[ny][nx] == 0:
                continue
            
            if isVisited[ny][nx] == 1:
                isVisited[ny][nx] = 0          
                dq.append((ny, nx))
                total += 1

    return total

dy = [-1, -1, 0, 1, 1, 1, 0, -1] # 12시부터 11시까지
dx = [0, 1, 1, 1, 0, -1, -1, -1]

while True:
    w, h = map(int, input().split())
    
    if w == 0 and h == 0:
        break
    
    board = [list(map(int, input().split())) for _ in range(h)]
    isVisited = board.copy()

    ans = 0
    for i in range(h):
        for j in range(w):
            if board[i][j] == 1:
                search(board, i, j, h, w, isVisited)
                ans += 1
                
    print(ans)