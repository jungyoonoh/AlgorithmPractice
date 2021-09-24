# 10845번 큐 (Queue) 
# https://www.acmicpc.net/problem/10845

from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
dq = deque()
for i in range(N):
    command = input().strip()

    if command == 'pop':
        if len(dq) != 0:            
            print(dq.popleft())
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
        dq.append(value)