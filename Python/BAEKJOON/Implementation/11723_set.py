# 11723번 집합 (Implementation) 
# https://www.acmicpc.net/problem/11723
from sys import stdin

N = int(stdin.readline())
s = set() # set 

for i in range(N):
    command = stdin.readline().rstrip().split()
    if command[0] == 'add':
        s.add(int(command[1]))
    elif command[0] == 'remove':
        if int(command[1]) in s: s.remove(int(command[1]))
    elif command[0] == 'check':
        print(1 if int(command[1]) in s else 0)
    elif command[0] == 'toggle':
        if int(command[1]) not in s: s.add(int(command[1]))
        else: s.remove(int(command[1]))
    elif command[0] == 'all':
        s.update([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    elif command[0] == 'empty':
        s = set()