# 프로그래머스 코딩테스트 연습 > 2017 팁스타운 > 예상 대진표
# https://programmers.co.kr/learn/courses/30/lessons/12985

def solution(n,a,b):
    answer = 0
    
    while a != b:
        a = (a+1) // 2
        b = (b+1) // 2
        answer += 1
    
    return answer