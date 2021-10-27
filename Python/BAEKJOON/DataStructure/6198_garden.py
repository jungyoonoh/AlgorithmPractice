# 6198번 옥상 정원 꾸미기 (Stack) 
# https://www.acmicpc.net/problem/6198

N = int(input())

stack = []
ans = 0
for i in range(N):
    height = int(input())

    if not stack:
        stack.append(height)
        continue

    while stack and stack[-1] <= height:
        info = stack.pop()
    
    stack.append(height)
    ans += len(stack) - 1

print(ans)