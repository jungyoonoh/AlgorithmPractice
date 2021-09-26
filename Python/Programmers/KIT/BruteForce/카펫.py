# 프로그래머스 코딩테스트 연습 > 완전탐색 > 소수찾기
# https://programmers.co.kr/learn/courses/30/lessons/42839

# 가로세로의 경우의 수를 구해야함

def solution(brown, yellow):
    answer = []
    height = 3
    while True:
        width = (brown - (height * 2)) // 2 + 2
        if (width - 2) * (height - 2) == yellow:
            answer = [width, height]
            break
        height += 1

    return answer

print(solution(24,24))