# 1676 팩토리얼 0의 개수 (Implementation) 
# https://www.acmicpc.net/problem/1676

N = int(input())
ans = 0
for i in range(1,4):
    ans += N // (5 ** i)
print(ans)