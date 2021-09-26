# 프로그래머스 코딩테스트 연습 > 스택큐 > 주식가격
# https://programmers.co.kr/learn/courses/30/lessons/42584

from collections import deque

def solution(prices):
    answer = [i for i in range(len(prices) - 1, -1, -1)]
    dq = deque()
    dq.append(0)
    for i in range(1, len(prices)):
        while dq and prices[i] < prices[dq[-1]]:
            top = dq.pop()
            answer[top] = i - top
        dq.append(i)

    return answer

print(solution([1, 2, 3, 4, 1, 2, 3, 1, 2]))