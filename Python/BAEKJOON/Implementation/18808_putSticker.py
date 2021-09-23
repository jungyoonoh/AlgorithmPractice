# 18808번 스티커 붙이기 (Implementation) 
# https://www.acmicpc.net/problem/18808

import sys
input = sys.stdin.readline

def rotated(a):
    n = len(a)
    m = len(a[0])

    result = [[0] * n for _ in range(m)]

    for i in range(n):
        for j in range(m):
            result[j][n-i-1] = a[i][j]
    return result

def checkCanPut(y, x, s):
    height = len(s) 
    width = len(s[0]) 
    for i in range(height):
        for j in range(width):
            if sticker[i][j] == 1 and board[y+i][x+j] == 1:
                return 0
    
    # 붙이기
    for i in range(height):
        for j in range(width):
            if sticker[i][j] == 1:
                board[y+i][x+j] = 1

    return 1

def do(s):
    flag = False
    height = len(s) 
    width = len(s[0]) 
    for i in range(0, N - height + 1):
        if flag: break
        for j in range(0, M - width + 1):
            if checkCanPut(i, j, s) == 1:
                flag = True
                break
        
    if flag: return True
    else: return False

N, M, K = map(int, input().split())
board = [[0 for _ in range(M)] for _ in range(N)]

for i in range(K):
    R, C = map(int, input().strip().split())
    sticker = [list(map(int, input().strip().split())) for _ in range(R)]
    if do(sticker) == True: continue
    else:
        for _ in range(3):
            sticker = rotated(sticker)
            if do(sticker) == True: break

ans = 0
for i in range(len(board)):
    ans += sum(board[i])
    
print(ans)