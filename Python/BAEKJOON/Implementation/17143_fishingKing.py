# 17143번 낚시왕 (Implementation) 
# https://www.acmicpc.net/problem/17143

from enum import Enum

class direction(Enum):
    UP = 1
    DOWN = 2
    RIGHT = 3
    LEFT = 4

def moveAndGet(pos):
    global totalWeight
    canFishingSpot = tuple(filter(lambda obj:obj[1] == pos, board))
    canFishingSpot = sorted(canFishingSpot, key=lambda grid:grid[0])
    if len(canFishingSpot) > 0:
        sharkIdx = board[canFishingSpot[0]]
        info = shark[sharkIdx[0]]
        totalWeight += info[4]
        shark.pop(sharkIdx[0])

    return 0

def do(totalMv, nowDir, pos):
    global R,C,M
    while totalMv:
        totalMv -= 1
        if nowDir == direction.UP.value:
            if pos == 1:
                pos += 1
                nowDir = direction.DOWN.value
            else:
                pos -= 1
        elif nowDir == direction.DOWN.value:
            if pos == R:
                pos -= 1
                nowDir = direction.UP.value
            else:
                pos += 1
        elif nowDir == direction.RIGHT.value:
            if pos == C:
                pos -= 1
                nowDir = direction.LEFT.value
            else:
                pos += 1
        elif nowDir == direction.LEFT.value:
            if pos == 1:
                pos += 1
                nowDir = direction.RIGHT.value
            else:
                pos -= 1

    return (pos, nowDir)

def moveShark():
    global R,C,M
    board.clear()
    
    # 이동
    for i in shark.keys():
        info = shark[i]
        y, x, speed, dir, size = info[0], info[1], info[2], info[3], info[4]
        mv = 0
        if dir == direction.UP.value or dir == direction.DOWN.value:
            mv = speed % (2 * (R - 1))
            data = do(mv, dir, y)
            y = data[0]
            dir = data[1]
        elif dir == direction.RIGHT.value or dir == direction.LEFT.value:
            mv = speed % (2 * (C - 1))
            data = do(mv, dir, x)
            x = data[0]
            dir = data[1]

        shark[i] = [y,x,speed,dir,size]
        if (y,x) in board:
            board[(y,x)] = board[(y,x)] + [i]
        else: board[(y,x)] = [i]

    # 잡아먹기  
    for info in board.keys():
        if len(board[info]) >= 2:
            data = []
            for i in board[info]:
                data.append((shark[i][4], i))
            data = sorted(data, key=lambda key:key[0])
            for i in range(0, len(data) - 1):
                shark.pop(data[i][1])
            winShark = data[len(data) - 1][1]
            board[info] = [winShark]
    
    return 0

R, C, M = map(int, input().split()) # 세로 가로 상어수
totalWeight = 0
fishingKing = 0 # 사람위치
shark = dict()
board = dict() # i번째 상어의 정보를 저장해둘 곳
for i in range(M):
    data = list(map(int, input().split())) # y, x, 속력, 이동방향, 크기 순
    shark[i] = data
    if (data[0], data[1]) in board:
        board[(data[0], data[1])] = board[(data[0], data[1])] + [i]
    else: board[(data[0], data[1])] = [i]

for _ in range(C):
    fishingKing += 1
    moveAndGet(fishingKing)
    moveShark()

print(totalWeight)