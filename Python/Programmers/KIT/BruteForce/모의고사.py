# 프로그래머스 코딩테스트 연습 > 완전탐색 > 모의고사
# https://programmers.co.kr/learn/courses/30/lessons/42840

def solution(answers):
    loop = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]
    score = [[0,1],[0,2],[0,3]]
    for i in range(len(answers)):
        if answers[i] == loop[0][i%len(loop[0])]:
            score[0][0] += 1
        if answers[i] == loop[1][i%len(loop[1])]:
            score[1][0] += 1
        if answers[i] == loop[2][i%len(loop[2])]:
            score[2][0] += 1
    score.sort(reverse=True)    
    answer = [score[0][1]]
    if score[0][0] == score[1][0]: answer.append(score[1][1])
    if score[0][0] == score[2][0]: answer.append(score[2][1])
    answer.sort()
    return answer

print(solution([1,3,2,4,2]))