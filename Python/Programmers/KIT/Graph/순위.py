# 프로그래머스 코딩테스트 연습 > 그래프 > 순위
# https://programmers.co.kr/learn/courses/30/lessons/49191

from collections import defaultdict
def solution(n, results):
    answer = 0
    winList = defaultdict(set)
    loseList = defaultdict(set)
    
    for i in range(len(results)):
        winner, loser = results[i][0], results[i][1]
        winList[winner].add(loser) # winner는 loser를 이김
        loseList[loser].add(winner) # loser는 winner에게 짐
        
    for i in range(1, n+1):
        for loser in winList[i]: # i번에게 진 애들
            loseList[loser].update(loseList[i]) # i번이 진 애들한테도 짐
        for winner in loseList[i]: # i번에게 이긴애들은
            winList[winner].update(winList[i]) # i번이 이긴애들도 다 이김
    
    for i in range(1, n+1):
        if len(winList[i]) + len(loseList[i]) == n-1:
            answer += 1

    return answer