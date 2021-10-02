# 프로그래머스 코딩테스트 연습 > 2019 KAKAO BLIND RECRUITMENT > 오픈 채팅방
# https://programmers.co.kr/learn/courses/30/lessons/42888

def solution(record):
    answer = []
    nicknameList = dict()
    
    for command in record:
        r = command.split()
        if r[0] != "Leave":
            nicknameList[r[1]] = r[2]

    for i in range(len(record)):
        t = record[i].split()
        if t[0] != "Change":
            action = "들어왔습니다." if t[0] == "Enter" else "나갔습니다."
            answer.append(nicknameList[t[1]] + "님이 " + action)
                
    return answer