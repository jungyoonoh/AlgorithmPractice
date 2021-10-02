# 프로그래머스 코딩테스트 연습 > Summer/Winter Coding(2019) > 멀쩡한 사각형
# https://programmers.co.kr/learn/courses/30/lessons/60057

# 그림을 그려보면 쉽게 알 수 있다

def solution(w,h):
    answer = 1
    
    big = max(w, h)
    small = min(w, h)
    
    while small:
        r = big % small
        big = small
        small = r
    
    answer = w * h - (w + h - big)
    
    return answer