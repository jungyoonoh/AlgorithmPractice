# 1427번 소트인사이드 (String) 
# https://www.acmicpc.net/problem/1427

import heapq

S = list(input())
heapq.heapify(S)
data = ""
for _ in range(len(S)):
    temp = str(heapq.heappop(S))
    data = temp + data

print(data)
