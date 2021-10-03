# 프로그래머스 코딩테스트 연습 > 2020 카카오 인턴십 > 수식 최대화
# https://programmers.co.kr/learn/courses/30/lessons/67257#

import re
import itertools
def solution(expression):
    answer = 0
    # 플 마 곱 : 0 1 2 
    
    numberList = re.split('\-|\+|\*', expression)
    exList = re.split('[0-9]', expression)
    exList = list(filter(None, exList))
    
    regex = ""
    
    if '+' in exList:    
        regex += '+'
    if '-' in exList:
        regex += '-'
    if '*' in exList:
        regex += '*'
    
    p = list(itertools.permutations(regex))
    
    M = -1
    print("가능한 조합 : ", p)
    for r in p: # 조합
        tempNL = numberList.copy()
        tempEL = exList.copy()       
        for ex in r:
            i = 0
            while i != len(tempEL) and ex in tempEL:
                if ex == tempEL[i]:                    
                    res = eval(str(tempNL[i]) + tempEL[i] + str(tempNL[i+1]))
                    del tempNL[i]
                    del tempNL[i]
                    del tempEL[i]
                    tempNL.insert(i, res)
                else: i += 1
                    
        M = max(M, abs(int(tempNL[0])))
    
    answer = M
    return answer