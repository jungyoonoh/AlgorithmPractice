# 18258번 queue2 (queue)
# https://www.acmicpc.net/problem/18258

from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
dq = deque()

for i in range(N):
    command = input().strip()
    if command[:4] == "push":
        command, num = command.split()
        dq.append(int(num))
    elif command == "pop":
        print(dq.popleft() if dq else -1)
    elif command == "size":
        print(len(dq))
    elif command == "empty":
        print(0 if dq else 1)
    elif command == "front":
        print(dq[0] if dq else -1)
    elif command == "back":
        print(dq[-1] if dq else -1)