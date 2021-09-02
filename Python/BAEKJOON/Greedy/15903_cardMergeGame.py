# 15903번 카드 합체 놀이 (Greedy) 
# https://www.acmicpc.net/problem/15903

import heapq # 이게 C++의 PriorityQueue. 
import sys
input = sys.stdin.readline

n,m = map(int, input().split())
data = list(map(int, input().split()))
heapq.heapify(data) # list를 Q화 하는것, 

for _ in range(m):
    a = heapq.heappop(data)
    b = heapq.heappop(data)
    heapq.heappush(data, a+b)
    heapq.heappush(data, a+b)

total = sum(data)
print(total) 