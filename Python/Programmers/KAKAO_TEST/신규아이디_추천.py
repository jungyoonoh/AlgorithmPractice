# 프로그래머스 코딩테스트 연습 > 2021 KAKAO BLIND RECRUITMENT > 신규 아이디 추천
# https://programmers.co.kr/learn/courses/30/lessons/72410

import re
def solution(new_id):
    
    new_id = new_id.lower() # 1    
    
    new_id = re.sub('[^A-Za-z0-9\-\_\.]', '', new_id) # 2
    
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