# 음료수 얼려 먹기

N, M = map(int, input().split()) # 세로 가로
board = [list(map(int, input())) for _ in range(N)]

def solution(y, x):
    if y < 0 or x < 0 or y >= N or x >= M:
        return

    if board[y][x]:
        return
    
    board[y][x] = 1

    solution(y, x + 1)
    solution(y + 1, x)
    solution(y, x - 1)
    solution(y - 1, x)

res = 0
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            solution(i, j)
            res += 1

print(res)
