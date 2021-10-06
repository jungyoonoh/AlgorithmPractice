# 7662번 이중 우선순위 큐 (Priority Queue) 
# https://www.acmicpc.net/problem/7662

import sys
import heapq

input = sys.stdin.readline

TC = int(input())
for _ in range(TC):
    step = int(input())
    maxList = []
    minList = []
    isVisited = [False] * (step + 1)
    for i in range(step):
        command, num = input().split()
        num = int(num)
        if command == 'I':
            heapq.heappush(maxList, (-num, i))
            heapq.heappush(minList, (num, i))
            isVisited[i] = True
        else:
            if num == 1:
                while maxList and not isVisited[maxList[0][1]]:
                    heapq.heappop(maxList)
                if maxList:
                    isVisited[maxList[0][1]] = False
                    heapq.heappop(maxList)
            else:
                while minList and not isVisited[minList[0][1]]:
                    heapq.heappop(minList)
                if minList:
                    isVisited[minList[0][1]] = False
                    heapq.heappop(minList)
    
    while maxList and not isVisited[maxList[0][1]]:
        heapq.heappop(maxList)
    
    while minList and not isVisited[minList[0][1]]:
        heapq.heappop(minList)

    if maxList and minList:
        print(-maxList[0][0], minList[0][0])
    else:
        print("EMPTY")
    