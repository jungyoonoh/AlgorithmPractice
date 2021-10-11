# 5525번 IOIOI (String) 
# https://www.acmicpc.net/problem/5525

N = int(input())
M = int(input())

S = list(input().strip())
stack = []

for i in range(M):
    if S[i] == 'O':
        continue
    stack.append(i)

answer = cnt = 0
for i in range(1, len(stack)):
    if stack[i] - stack[i-1] == 2:
        cnt += 1
    else:
        cnt = 0
    
    if cnt >= N:
        answer += 1

print(answer)