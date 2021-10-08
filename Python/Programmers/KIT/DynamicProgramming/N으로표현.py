# 프로그래머스 코딩테스트 연습 > 동적 계획법(Dynamic Programming) > N으로 표현
# https://programmers.co.kr/learn/courses/30/lessons/42895

def solution(N, number):
    answer = 0
    
    S = [0, {N}]
    if N == number: return 1
    
    for i in range(2, 9):
        dataSet = {int(str(N)*i)}
        for j in range(1, i // 2 + 1):
            for k in S[j]:
                for l in S[i-j]:
                    dataSet.add(k+l)
                    dataSet.add(k-l)
                    dataSet.add(l-k)
                    dataSet.add(k*l)
                    if k != 0:
                        dataSet.add(l // k)
                    if l != 0:
                        dataSet.add(k // l)
            
        if number in dataSet:
            return i
        S.append(dataSet)
    
    return -1