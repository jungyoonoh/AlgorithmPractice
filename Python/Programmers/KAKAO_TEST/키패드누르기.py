# 프로그래머스 코딩테스트 연습 > 2020 카카오 인턴십 > 키패드 누르기
# https://programmers.co.kr/learn/courses/30/lessons/67256

def solution(numbers, hand):
    answer = []
    ly = ry = 3
    lx = 0 
    rx = 2
    for i in numbers:
        if i % 3 == 1:
            answer.append('L')
            ly = i // 3
            lx = 0
            continue
        
        if i % 3 == 0 and i != 0:
            answer.append('R')
            ry = (i // 3) - 1
            rx = 2
            continue
        
        center = i // 3 if i != 0 else 3
        
        if abs(center - ly) + abs(1 - lx) > abs(center - ry) + abs(1 - rx):
            answer.append('R')
            ry = center
            rx = 1
            continue
            
        if abs(center - ly) + abs(1 - lx) < abs(center - ry) + abs(1 - rx):
            answer.append('L')
            ly = center
            lx = 1
            continue
            
        if hand == "right":
            answer.append('R')
            ry = center
            rx = 1
            continue
        
        if hand == "left":
            answer.append('L')
            ly = center
            lx = 1
            continue
            
    return ''.join(answer)