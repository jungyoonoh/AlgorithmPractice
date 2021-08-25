# 2828번 사과 담기 게임 (Greedy) 
# https://www.acmicpc.net/problem/2828

N, M = map(int, input().split())
appleNum = int(input())
left = 1
right = left + M - 1
move = 0
for _ in range(appleNum):
    applePos = int(input())
    if applePos < left:
        move += left - applePos
        left = applePos
        right = left + M - 1
    elif applePos > right:
        move += applePos - right
        right = applePos
        left = right - M + 1 

print(move)