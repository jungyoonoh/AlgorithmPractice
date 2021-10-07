# 프로그래머스 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 단어변환
# https://programmers.co.kr/learn/courses/30/lessons/43163

answer = 9999
def solution(begin, target, words):
    global answer
    isChanged = [False] * len(words)
    change(begin, target, words, isChanged, 0)
    if answer == 9999:
        answer = 0
    return answer

def check(a, b):
    cnt = 0
    for i in range(len(a)):
        if cnt > 1: return False
        if a[i] != b[i]:
            cnt += 1
    
    if cnt == 1: return True
    return False

def change(now, target, words, isChanged, count):
    global answer
    if now == target:
        answer = min(answer, count)
        return
    for i in range(len(words)):
        cnt = 0
        if words[i] != now:
            if check(words[i], now) and not isChanged[i]:
                isChanged[i] = True
                change(words[i], target, words, isChanged, count + 1)
                isChanged[i] = False
