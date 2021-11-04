# 1665번 가운데를 말해요 (Priority Queue) 
# https://www.acmicpc.net/problem/1665

import sys
import heapq

input = sys.stdin.readline

N = int(input())

lessQueue = []
moreQueue = []

ans = []

for i in range(N):
    num = int(input())
    
    if len(lessQueue) == len(moreQueue):
        heapq.heappush(lessQueue, (-num, num))
    else:
        heapq.heappush(moreQueue, (num, num))

    if moreQueue and lessQueue[0][1] > moreQueue[0][1]:
        # swap
        less = heapq.heappop(moreQueue)[1]
        more = heapq.heappop(lessQueue)[1]
        heapq.heappush(lessQueue, (-less, less))
        heapq.heappush(moreQueue, (more, more))
    
    ans.append(lessQueue[0][1])

for i in ans:
    print(i)