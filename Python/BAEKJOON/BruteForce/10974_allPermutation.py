# 10974번 모든 순열 (BruteForce) 
# https://www.acmicpc.net/problem/10974

def findAll(num, N, ans):
    if num == N:
        print(*ans)
        return
    
    for i in range(1, N+1):
        if not isSelected[i]:
            isSelected[i] = True
            ans.append(i)
            findAll(num + 1, N, ans)
            isSelected[i] = False
            ans.pop()

N = int(input())

isSelected = [False] * (N+1)

findAll(0, N, [])