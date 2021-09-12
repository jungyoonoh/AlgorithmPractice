# 프로그래머스 코딩테스트 연습 > 힙(Heap) > 더 맵게
# https://programmers.co.kr/learn/courses/30/lessons/42626

import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0] < K:
        if len(scoville) <= 1:
            answer = -1
            break  
        m1 = heapq.heappop(scoville)
        m2 = heapq.heappop(scoville)
        heapq.heappush(scoville, m1 + m2 * 2)
        answer += 1
        if scoville[0] >= K:
            break     

    return answer

print(solution([1, 2, 3, 9, 10, 12],7))