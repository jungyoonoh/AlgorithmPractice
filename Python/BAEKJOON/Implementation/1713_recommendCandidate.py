# 1713 후보 추천하기 (Implementation) 
# https://www.acmicpc.net/problem/1713

import sys
N = int(input())
recommend = int(input())
res = list(map(int, sys.stdin.readline().split()))
candidate = dict()

for i in range(recommend):
    if res[i] in candidate:
        # 이미 있음
        candidate[res[i]][0] += 1
    else: 
        # 꽉찼을때        
        if len(candidate) < N:
            # 비어있음
            candidate[res[i]] = [1, i] # i번째 등록된 녀석임. (오래됨 판단)
        else:
            # 없음
            delCandidate = sorted(candidate.items(), key = lambda x: (x[1][0], x[1][1]))
            minCandidate = delCandidate[0][0]
            del(candidate[minCandidate])
            candidate[res[i]] = [1, i]

ans = list(sorted(candidate.keys()))
print(*ans)
