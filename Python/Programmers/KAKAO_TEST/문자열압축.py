# 프로그래머스 코딩테스트 연습 > 2020 KAKAO BLIND RECRUITMENT > 문자열 압축
# https://programmers.co.kr/learn/courses/30/lessons/60057

def solution(s):
    answer = 0
    lenList = []
    for i in range(1, len(s) // 2 + 1): # 패턴 길이
        count = 1
        find = s[:i]
        res = ""
        for j in range(i, len(s), i): # 찾기
            if find == s[j:j+i]:
                count += 1
            else:
                strZip = str(count) + find if count != 1 else find
                res += strZip
                find = s[j:j+i]
                count = 1
                
        strZip = str(count) + find if count != 1 else find
        res += strZip
        lenList.append(len(res))
    
    if len(lenList) == 0:
        answer = 1
    else: answer = min(lenList)

    return answer