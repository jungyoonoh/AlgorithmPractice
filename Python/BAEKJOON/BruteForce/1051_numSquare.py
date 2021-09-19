# 1051번 숫자 정사각형 (BruteForce) 
# https://www.acmicpc.net/problem/1051

N, M = map(int, input().split())

board = [list(map(int, input().strip())) for _ in range(N)]
r = min(N, M)
square = 1
for i in range(r, 0, -1):
    for j in range(0, N - i + 1):
        for k in range(0, M - i + 1):
            if board[j][k] == board[j + i - 1][k] and board[j][k] == board[j][k + i - 1] and board[j][k] == board[j + i - 1][k + i - 1]:
                square = max(square, i**2)

print(square)
