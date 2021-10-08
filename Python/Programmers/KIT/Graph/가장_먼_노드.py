# 프로그래머스 코딩테스트 연습 > 그래프 > 가장 먼 노드
# https://programmers.co.kr/learn/courses/30/lessons/49189

from collections import deque
def solution(n, edge):
    answer = 0
    info = [[] for _ in range(n+1)]
    isVisited = [False] * (n+1)
    distance = [0] * (n+1)
    dq = deque([1])
    
    for i in range(len(edge)):
        start, end = edge[i][0], edge[i][1]
        info[start].append(end)
        info[end].append(start)
    
    isVisited[1] = True
    while dq:
        x = dq.popleft()       
        for i in info[x]:
            if not isVisited[i]:
                isVisited[i] = True
                distance[i] = distance[x] + 1
                dq.append(i)
    
    maxLen = max(distance)
    answer = distance.count(maxLen)
    
    return answer