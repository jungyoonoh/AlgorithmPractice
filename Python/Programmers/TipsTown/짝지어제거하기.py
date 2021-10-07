# 프로그래머스 코딩테스트 연습 > 2017 팁스타운 > 짝지어 제거하기
# https://programmers.co.kr/learn/courses/30/lessons/12973

from collections import deque
def solution(s):
    answer = -1
    
    dq = deque()
    
    for i in range(len(s)):
        if not dq:
            dq.append(s[i])
        elif dq[-1] == s[i]:
            dq.pop()
        else:
            dq.append(s[i])
    
    if dq:
        answer = 0
    else: answer = 1
    
    return answer