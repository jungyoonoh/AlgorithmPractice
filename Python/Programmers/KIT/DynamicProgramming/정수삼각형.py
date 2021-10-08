# 프로그래머스 코딩테스트 연습 > 동적 계획법(Dynamic Programming) > 정수 삼각형
# https://programmers.co.kr/learn/courses/30/lessons/43238

def solution(triangle):
    answer = 0
    M = len(triangle)
    cache = [[-1 for _ in range(M)] for _ in range(M)]
    cache[0][0] = triangle[0][0]
    
    for i in range(1, M):
        for j in range(i+1):
            if j == 0:
                cache[i][j] = cache[i-1][j] + triangle[i][j]
            elif j == i:
                cache[i][j] = cache[i-1][j-1] + triangle[i][j]
            else:
                cache[i][j] = max(cache[i-1][j], cache[i-1][j-1]) + triangle[i][j]
    
    answer = max(cache[M-1])
    
    return answer