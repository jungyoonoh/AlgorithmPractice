# 1977번 초콜릿 자르기 (Math) 
# https://www.acmicpc.net/problem/1977
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

import math

M = int(input())
N = int(input())
s = []
for i in range(math.floor(math.sqrt(M)), math.floor(math.sqrt(N) + 1)):
    if i * i >= M and i * i <= N:
        s.append(i*i)
        
if len(s) == 0:
    print(-1)
else: 
    print(sum(s))
    print(min(s))