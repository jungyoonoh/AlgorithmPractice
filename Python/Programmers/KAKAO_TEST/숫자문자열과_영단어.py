# 프로그래머스 코딩테스트 연습 > 2021 카카오 채용연계형 인턴십 > 숫자 문자열과 영단어
# https://programmers.co.kr/learn/courses/30/lessons/81301

def solution(s):
    answer = 0
    eng = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    num = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    
    for i in range(10):
        s = s.replace(eng[i], num[i])
            
    return int(s)
