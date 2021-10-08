# 프로그래머스 코딩테스트 연습 > 동적 계획법(Dynamic Programming) > 등굣길
# https://programmers.co.kr/learn/courses/30/lessons/42898

def solution(m, n, puddles):
    answer = 0
    # m 가로 n 세로
    cache = [[1 for _ in range(m)] for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            for k in range(len(puddles)):
                cache[puddles[k][1] - 1][puddles[k][0] - 1] = 0
    
    flag = False
    for i in range(1, n):
        if flag: 
            cache[i][0] = 0
        if cache[i][0] == 0:
            flag = True
    
    flag = False
    for i in range(1, m):
        if flag: 
            cache[0][i] = 0
        if cache[0][i] == 0:
            flag = True
            
    for i in range(1, n):
        for j in range(1, m):
            if cache[i][j] != 0:
                cache[i][j] = (cache[i-1][j] + cache[i][j-1]) % 1_000_000_007
    
    print(cache)
    answer = cache[n-1][m-1]
    
    return answer