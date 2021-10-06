# 1781번 컵라면 (Greedy) 
# https://www.acmicpc.net/problem/1781

import heapq

N = int(input())

data = []

for i in range(N):
    deadline, cup = map(int, input().split())
    data.append((deadline, cup))

data = sorted(data, key=lambda x:(x[0], x[1]))

pq = []
for i in range(N):
    if len(pq) < data[i][0]:
        heapq.heappush(pq, data[i][1])
    elif pq[0] < data[i][1]:
        heapq.heappop(pq)
        heapq.heappush(pq, data[i][1])

print(sum(pq)) 