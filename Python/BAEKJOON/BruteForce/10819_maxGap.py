# 10819번 차이를 최대로 (BruteForce) 
# https://www.acmicpc.net/problem/10819

ans = []
N = int(input())
A = list(map(int, input().split()))
M = -1
checked = [False] * N
def solution(cnt):
    global M
    if cnt == N:
        s = 0
        for i in range(len(ans) - 1):
            s += abs(ans[i] - ans[i+1])
        if s > M: M = s
    
    for i in range(len(A)):
        if not checked[i]:
            checked[i] = True
            ans.append(A[i])
            solution(cnt+1)
            ans.pop()
            checked[i] = False

solution(0)
print(M)