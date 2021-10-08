# 프로그래머스 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 타겟넘버
# https://programmers.co.kr/learn/courses/30/lessons/43165

def find(signList, numbers, target, idx):
    global answer
    if len(signList) == len(numbers):
        s = 0
        for i in range(idx):
            s += signList[i] * numbers[i]
        if s == target:
            answer += 1
        return

    for i in range(-1, 2, 2):
        signList.append(i)
        find(signList, numbers, target, idx + 1)
        signList.pop()

answer = 0
def solution(numbers, target):
    find([], numbers, target, 0)
    return answer

print(solution([1,1,1,1,1], 3))