# 9935번 문자열 폭발 (String) 
# https://www.acmicpc.net/problem/9935

from collections import deque
s = list(input())
bomb = list(input())
stack = []
bl = len(bomb)
for i in range(len(s)):
    stack.append(s[i])
    if len(stack) >= bl and stack[-1] == bomb[-1]:
        if stack[-bl:] == bomb:
            del stack[-bl:]

if len(stack) == 0:
    print("FRULA")
else:
    print(''.join(stack))