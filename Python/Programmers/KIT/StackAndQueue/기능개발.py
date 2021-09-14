# 프로그래머스 코딩테스트 연습 > 스택큐 > 기능개발
# https://programmers.co.kr/learn/courses/30/lessons/42586

from collections import deque

def solution(progresses, speeds):
    answer = []
    dq = deque(progresses)
    sdq = deque(speeds)
    while True:
        for i in range(len(dq)):
            dq[i] += sdq[i]
        if dq[0] >= 100:
            cnt = 0
            while len(dq) >= 1:
                if dq[0] >= 100:
                    dq.popleft()
                    sdq.popleft()
                    cnt += 1
                else: break
            answer.append(cnt)
        
        if len(dq) < 1:
            break
        
    return answer


print(solution([93, 30, 55], [1, 30, 5]))