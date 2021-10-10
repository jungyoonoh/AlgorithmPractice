# 10872번 팩토리얼 (Implementation) 
# https://www.acmicpc.net/problem/10872

N = int(input())

t = 1
for i in range(1, N+1):
    t *= i

print(t)