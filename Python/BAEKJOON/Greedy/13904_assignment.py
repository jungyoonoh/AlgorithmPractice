# 13904번 과제 (Greedy) 
# https://www.acmicpc.net/problem/13904

import heapq

N = int(input())

data = []
pq = []

for i in range(N):
    d, w = map(int, input().split())
    data.append((d, w))
    
data.sort(key = lambda x:(x[0], -x[1]))

day = 1
for info in data:
    if day <= info[0]:
        heapq.heappush(pq, info[1])
        day += 1
        continue
    
    if pq[0] < info[1]:
        heapq.heappop(pq)
        heapq.heappush(pq, info[1])
        
print(sum(pq))