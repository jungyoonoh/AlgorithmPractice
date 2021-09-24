# 10866번 덱 (Deque) 
# https://www.acmicpc.net/problem/10866

from collections import deque
import sys
input = sys.stdin.readline

dq = deque()
N = int(input())
for i in range(N):
    command = input().strip()
    if command == 'pop_front':
        if len(dq) != 0:
            print(dq.popleft())
        else: print(-1)
    elif command == 'pop_back':
        if len(dq) != 0:
            print(dq.pop())
        else: print(-1)
    elif command == 'size':
        print(len(dq))
    elif command == 'empty':
        if len(dq) == 0:
            print(1)
        else: print(0)
    elif command == 'front':
        if len(dq) != 0:
            print(dq[0])
        else: print(-1)
    elif command == 'back':
        if len(dq) != 0:
            print(dq[len(dq) - 1])
        else: print(-1)
    else:
        command, value = command.split()
        if command == 'push_front':
            dq.appendleft(value)
        else: dq.append(value)