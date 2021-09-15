# 프로그래머스 코딩테스트 연습 > 탐욕법 > 구명보트
# https://programmers.co.kr/learn/courses/30/lessons/42885

from collections import deque

def solution(people, limit):
    answer = 0
    people.sort()
    dq = deque(people)
    while len(dq):
        now = 0
        while len(dq) and now + dq[-1] <= limit:
            now += dq[-1]
            dq.pop()
        while len(dq) and now + dq[0] <= limit:
            now += dq[0]
            dq.popleft()
        answer += 1

    return answer

print(solution([70, 50, 80, 50]	,100))