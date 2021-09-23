# 20057번 마법사 상어와 토네이도 (Implementation) 
# https://www.acmicpc.net/problem/20057

from enum import Enum

class direction(Enum):
    LEFT = 0
    DOWN = 1
    RIGHT = 2
    UP = 3

def spread(y, x, dir):
    global N
    outAmount = 0
    total = 0
    for i in range(9):
        dy, dx = variance[dir][i][0], variance[dir][i][1]
        ny, nx = y + dy, x + dx
        spreadAmount = (board[y][x] * percent[i]) // 100
        total += spreadAmount
        if ny < 0 or ny >= N or nx < 0 or nx >= N:
            outAmount += spreadAmount
            continue
        board[ny][nx] += spreadAmount
    dy, dx = variance[dir][9][0], variance[dir][9][1]
    alphaY, alphaX = y + dy, x + dx
    remain = board[y][x] - total
    if alphaY < 0 or alphaY >= N or alphaX < 0 or alphaX >= N:
        outAmount += remain
    else:
        board[alphaY][alphaX] += remain

    board[y][x] = 0
    return outAmount

# 토네이도의 영향권 LDRU
variance = [
    [(-1, 1), (-2, 0), (-1, 0), (-1, -1), (0, -2), (1, -1), (1, 0), (2, 0), (1, 1), (0, -1)],
    [(-1, -1), (0, -2), (0, -1), (1, -1), (2, 0), (1, 1), (0, 1), (0, 2), (-1, 1), (1, 0)],
    [(1, -1), (2, 0), (1, 0), (1, 1), (0, 2), (-1, 1), (-1, 0), (-2, 0), (-1, -1), (0, 1)],
    [(1, 1), (0, 2), (0, 1), (-1, 1), (-2, 0), (-1, -1), (0, -1), (0, -2), (1, -1), (-1, 0)]
]

moveY = [0, 1, 0, -1]
moveX = [-1, 0, 1, 0]

percent = [1, 2, 7, 10, 5, 10, 7, 2, 1] # 반시계

N = int(input())
board = [list(map(int, input().strip().split())) for _ in range(N)]

dir = -1
repeat = 1
y = x = N // 2
ans = 0
flag = True
while flag:
    dir = (dir + 1) % 4
    for i in range(repeat):
        y += moveY[dir]
        x += moveX[dir]
        ans += spread(y, x, dir)
        if y == 0 and x == 0: 
            flag = False
            break
    if dir % 2 == 1: repeat += 1

print(ans)