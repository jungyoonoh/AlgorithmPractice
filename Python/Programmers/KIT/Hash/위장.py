# 프로그래머스 코딩테스트 연습 > 해시 > 위장
# https://programmers.co.kr/learn/courses/30/lessons/42578

def solution(clothes):
    d = dict()
    for i in clothes:
        d[i[1]] = d.get(i[1], 1) + 1
    answer = 1
    for v in d.values():
        answer *= v
    return answer - 1