# 2493번 탑 (Stack) 
# https://www.acmicpc.net/problem/2493

N = int(input())
tower = list(map(int, input().split()))

stack = []
ans = [0] * len(tower)
for i in range(len(tower) - 1, -1, -1):
    if not stack:
        stack.append((tower[i], i))
        continue
        
    while stack and stack[-1][0] < tower[i]:
        info = stack.pop()
        ans[info[1]] = i+1

    stack.append((tower[i], i))

print(*ans)