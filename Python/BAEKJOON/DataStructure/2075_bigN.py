# 2075번 N번째 큰 수 (PQ) 
# https://www.acmicpc.net/problem/2075

import heapq

N = int(input())
pq = []

data = list(map(int, input().split()))
for i in data:
    heapq.heappush(pq, i)
    
for _ in range(N - 1):
    data = list(map(int, input().split()))
    for i in data:
        if i > pq[0]:
            heapq.heappush(pq, i)
            heapq.heappop(pq)

print(pq[0])