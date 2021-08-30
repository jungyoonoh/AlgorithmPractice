# 11723번 집합 (Implementation) 
# https://www.acmicpc.net/problem/11723

N = int(input())

s = set() # set 

for i in range(N):
    command = input()
    if command == 'all':
        s.update([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
        continue
    elif command == 'empty':
        s.clear()
        continue

    command, num = command.split()
    num = int(num)
    if command == 'add':
        s.add(num)
    elif command == 'remove':
        if num in s: s.remove(num)
    elif command == 'check':
        print("1" if num in s else "0")
    elif command == 'toggle':
        if num not in s: s.add(num)
        else: s.remove(num)