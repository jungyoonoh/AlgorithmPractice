# 11729번 하노이 탑 이동 순서 (Implementation) 
# https://www.acmicpc.net/problem/11729

N = int(input())

def hanoi(n, a, b, c):
    if n == 1:
        ans.append((a, c))
    else:
        hanoi(n-1, a, c, b)
        ans.append((a,c))
        hanoi(n-1, b, a, c)

ans = []
hanoi(N, 1,2,3)
print(len(ans))
for i in ans:
    print(*i)