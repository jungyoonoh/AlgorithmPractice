# 1343번 폴리오미노 (Greedy) 
# https://www.acmicpc.net/problem/1343

board = input()
first = board.replace('XXXX', 'AAAA')
second = first.replace('XX', 'BB')

if 'X' in second: print(-1)
else: print(second)