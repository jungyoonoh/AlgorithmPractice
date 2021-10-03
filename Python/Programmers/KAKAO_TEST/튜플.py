# 프로그래머스 코딩테스트 연습 > 2020 카카오 개발자 겨울 인턴십 > 튜플
# https://programmers.co.kr/learn/courses/30/lessons/64065

def solution(s):
    answer = []
    temp = s[1:len(s)-1]
    data = temp.split('},')
    last = len(data) - 1
    for i in range(len(data)):
        data[i] = data[i][1:]
        if i == last:
            data[i] = data[i][:len(data[i]) - 1]
    data = sorted(data, key=lambda obj:len(obj))
    
    sav = [set()] * len(data)
    sav[0].add(int(data[0]))
    answer.append(int(data[0]))
    for i in range(1, len(data)):
        sav[i] = set(list(map(int, data[i].split(','))))
    
    for i in range(1, len(sav)):
        t = sav[i] - sav[i-1]
        t = list(t)
        answer.append(t[0])
    
    return answer