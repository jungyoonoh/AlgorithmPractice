# 2447번 별찍기 10 (Recursion) 
# https://www.acmicpc.net/problem/2447

def drawStar(board, n, y, x):
    if n == 1:
        board[y][x] = '*'
        return

    nextN = n // 3
    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                continue
            drawStar(board, nextN, y + i * nextN, x + j * nextN)
    

N = int(input())

board = [[' ' for _ in range(N)] for _ in range(N)]

drawStar(board, N, 0, 0)

for row in board:
    print(''.join(row))