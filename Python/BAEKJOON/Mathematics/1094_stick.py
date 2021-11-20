# 1094번 막대기 (Math) 
# https://www.acmicpc.net/problem/1094

X = int(input())

stickLen = [64, 32, 16, 8, 4, 2, 1]
cnt = 0
for i in stickLen:
    if i <= X:
        X -= i
        cnt += 1
        
print(cnt)