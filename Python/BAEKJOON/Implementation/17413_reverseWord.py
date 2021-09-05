# 17413번 단어 뒤집기 2 (Implementation) 
# https://www.acmicpc.net/problem/17413

from collections import deque

S = input()
q = deque()
ans = ""
check = False
for i in range(len(S)):
    char = S[i]
    if char == '<':
        loop = len(q)
        for j in range(loop):
            ans += q.pop()
        check = True
        q.append(char)
    elif char == '>':
        q.append(char)
        loop = len(q)
        for j in range(loop):
            ans += q.popleft()
        check = False
    elif char == ' ' and check == False:
        loop = len(q)
        for j in range(loop):
            ans += q.pop()
        ans += char
    else: q.append(char)
    if i == len(S) - 1:
        loop = len(q)
        for j in range(loop):
            ans += q.pop()
        break

print(ans)