# 12851번 숨바꼭질2 (BruteForce) 
# https://www.acmicpc.net/problem/12851

from collections import deque

N, K = map(int, input().split())

size = 100001
board = [[-1, 0] for _ in range(size)]

dq = deque()
dq.append(N)

board[N][0] = 0
board[N][1] = 1

while dq:
    x = dq.popleft()
    
    for nx in (x-1, x+1, x*2):
        if nx < 0 or nx >= size:
            continue
        if board[nx][0] == -1:
            board[nx][0] = board[x][0] + 1
            board[nx][1] = board[x][1]
            dq.append(nx)
        elif board[nx][0] == board[x][0] + 1:
            board[nx][1] += board[x][1]
        
print(board[K][0])
print(board[K][1])