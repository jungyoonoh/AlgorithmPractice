# 프로그래머스 코딩테스트 연습 > 탐욕법 > 섬 연결하기
# https://programmers.co.kr/learn/courses/30/lessons/42861

def solution(n, costs):
    answer = 0
    costs = sorted(costs, key=lambda obj:obj[2])
    info = set([costs[0][0]])
    
    while len(info) != n:
        for i in range(len(costs)):
            if (costs[i][0] in info and costs[i][1] not in info) or (costs[i][0] not in info and costs[i][1] in info):
                answer += costs[i][2]
                info.update([costs[i][0], costs[i][1]])
                costs[i] = [-1, -1, -1]
                break
    
    return answer