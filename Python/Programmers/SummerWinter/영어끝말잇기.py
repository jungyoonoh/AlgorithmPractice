# 프로그래머스 코딩테스트 연습 > Summer/Winter Coding(~2018) > 영어 끝말잇기
# https://programmers.co.kr/learn/courses/30/lessons/12981

def solution(n, words):
    answer = []
    
    last = words[0]
    turn = 1
    wordList = set()
    wordList.add(last)
    flag = False
    for i in range(1, len(words)):
        if last[-1] != words[i][0]:
            flag = True
            break
        if words[i] not in wordList:
            wordList.add(words[i])
            last = words[i]
            turn += 1
        else:
            flag = True
            break
    if flag:
        answer.append((turn % n) + 1)
        answer.append((turn // n) + 1)
    else: 
        answer.append(0)
        answer.append(0)
    return answer