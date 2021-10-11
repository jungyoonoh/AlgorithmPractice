# 1074번 Z (Recursion) 
# https://www.acmicpc.net/problem/1074

cnt = 0
N, R, C = map(int, input().split())
def search(n, y, x):
    global cnt
    if y == R and x == C:
        print(cnt)
        return
    if n == 1: 
        cnt += 1   
        return
    
    if not (y <= R and R < y + n and x <= C and C < x + n):
        cnt += n * n
        return

    nextN = n // 2
    for i in range(2):
        for j in range(2):
            search(nextN, y + i * nextN, x + j * nextN)

search(2**N, 0, 0)