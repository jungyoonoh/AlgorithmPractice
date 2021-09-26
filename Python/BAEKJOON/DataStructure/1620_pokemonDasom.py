# 1620번 나는야 포켓몬 마스터 이다솜! (Dict) 
# https://www.acmicpc.net/problem/1620

import sys
input = sys.stdin.readline
N, M = map(int, input().split())
d = dict()

for i in range(N):
    pokemon = input().strip()
    d[str(i + 1)] = pokemon
    d[pokemon] = i + 1

for i in range(M):
    quiz = input().strip()
    print(d[quiz])
    