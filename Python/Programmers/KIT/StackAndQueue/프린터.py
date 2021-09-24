# 프로그래머스 코딩테스트 연습 > 스택큐 > 프린터
# https://programmers.co.kr/learn/courses/30/lessons/42587

from collections import deque

def solution(priorities, location):
    answer = 0
    dq = deque() # 우선순위 포함한 녀석
    printer = deque(priorities) # 실제로 돌아갈 녀석
    for i in range(len(priorities)):
        dq.append((priorities[i], i)) # 원래 번호를 가지고 있도록
        
    while printer:
        if printer[0] < max(printer):
            printer.append(printer.popleft())
            dq.append(dq.popleft())
        else:
            answer += 1
            if dq[0][1] == location:
                break
            else:
                dq.popleft()
                printer.popleft()

    return answer

print(solution([2, 1, 3, 2], 2))