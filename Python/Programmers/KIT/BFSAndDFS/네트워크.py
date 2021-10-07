# 프로그래머스 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 네트워크
# https://programmers.co.kr/learn/courses/30/lessons/43162

def solution(n, computers):
    isVisited = [False] * (n)    
    answer = 0
    
    for i in range(len(computers)):
        if not isVisited[i]:
            answer += 1
            search(computers, i, isVisited)
    
    return answer


def search(computers, now, isVisited):
    isVisited[now] = True
    for i in range(len(computers[now])):
        if computers[now][i] == 1 and i != now and not isVisited[i]:
            search(computers, i, isVisited)
    return 