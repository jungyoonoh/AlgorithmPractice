# 2563번 색종이 (Implementation) 
# https://www.acmicpc.net/problem/2563

N = int(input())
arr = [[0 for _ in range(101)] for _ in range(101)] # 100 x 100 (0 ~ 100)
data = []
for i in range(N):
    x,y = map(int, input().split())
    for i in range(y, y+10):
        for j in range(x, x+10):
            arr[i][j] = 1
ans = 0
for i in arr: # i는 1차원 list에 대응
    ans += sum(i) # 리스트의 합 sum()

print(ans)