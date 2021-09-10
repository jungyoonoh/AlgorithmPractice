# 프로그래머스 코딩테스트 연습 > 해시 > 완주하지 못한 선수
# https://programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    d = dict()
    for i in participant:
        d[i] = d.get(i, 0) + 1 # i를 key로 갖고, 이미 있으면 있는거 + 1 없으면 default 0 + 1 
    for i in completion:
        d[i] -= 1
    for i in d:
        if d[i] == 1: answer = i       
    return answer 

print(solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"]))