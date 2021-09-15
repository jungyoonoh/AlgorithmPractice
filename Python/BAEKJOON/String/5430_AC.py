# 5430번 AC (String) 
# https://www.acmicpc.net/problem/5430

from collections import deque
import sys
input = sys.stdin.readline

T = int(input().strip())
for i in range(T):
    p = list(input().strip())
    dq = deque(p)
    n = int(input().strip())
    x = input().strip()
    x = x[1:-1]
    if len(x) > 1:
        x = x.split(',')
    num = deque(x)
    rv = 0
    flag = False
    for j in range(len(dq)):
        if dq[j] == 'R':
            rv += 1
        elif dq[j] == 'D':
            if len(num) >= 1:
                if rv % 2 == 1: num.pop()
                else: num.popleft()
            else:
                flag = True
                print('error')
                break
    if not flag:
        if rv % 2 == 1:
            num.reverse()
        print('[' + ','.join(num) + ']')
