# 1012번 유기농 배추 (BruteForce) 
# https://www.acmicpc.net/problem/1012

def findSpot(y, x):
    global M, N
    board[y][x] = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= N or nx >= M:
            continue
        if board[ny][nx] == 1:
            findSpot(ny,nx)

    return 0

T = int(input())
dy = [0, 1, 0, -1] # 오 아 왼 위
dx = [1, 0, -1, 0] 
while T:
    M, N, K = map(int, input().split()) # 가로 세로 배추 양

    board = [[0 for _ in range(M)] for _ in range(N)]

    warm = 0
    for i in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1

    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                warm += 1
                findSpot(i, j)

    print(warm)
    T -= 1