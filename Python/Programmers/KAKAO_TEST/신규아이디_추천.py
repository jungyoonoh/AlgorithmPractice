# 프로그래머스 코딩테스트 연습 > 2021 KAKAO BLIND RECRUITMENT > 신규 아이디 추천
# https://programmers.co.kr/learn/courses/30/lessons/72410

import re
def solution(new_id):
    
    new_id = new_id.lower() # 1    
    
    # 대문자, 소문자, 숫자, -, _, . 을 제외한 모든 문자를 빈칸으로 치환
    new_id = re.sub('[^A-Za-z0-9\-\_\.]', '', new_id) # 2
    
    # .+ == .이 최소한 1회 이상 반복될 경우 .으로 치환
    new_id = re.sub('\.+', '.', new_id) # 3

    if new_id and new_id[0] == '.': # 4
        new_id = new_id[1:]
    if new_id and new_id[-1] == '.':
        new_id = new_id[:len(new_id) - 1]

    if len(new_id) == 0: # 5
        new_id += 'a'        
        
    if len(new_id) >= 16: # 6
        new_id = new_id[:15]
        if new_id[-1] == '.':
            new_id = new_id[:len(new_id) - 1]

    while(len(new_id) <= 2): # 7
        new_id += new_id[-1]
    
    return new_id

print(solution("...!@BaT#*..y.abcdefghijklm"))
print(solution("z-+.^."))
print(solution("=.="))
print(solution("123_.def"))
print(solution("abcdefghijklmn.p"))