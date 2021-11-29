# 2109번 순회강연 (Greedy) 
# https://www.acmicpc.net/problem/2109

import heapq

N = int(input())

pq = []
info = []
for i in range(N):
    p, d = map(int, input().split())
    info.append((p, d))
    
info = sorted(info, key = lambda x : (x[1], -x[0]))

day = 1
for data in info:
    if data[1] >= day:
        heapq.heappush(pq, data[0])
        day += 1
        continue
    
    if pq[0] < data[0]:
        heapq.heappop(pq)
        heapq.heappush(pq, data[0])

print(sum(pq))