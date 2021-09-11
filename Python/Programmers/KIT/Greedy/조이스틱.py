# 프로그래머스 코딩테스트 연습 > 탐욕법(Greedy) > 조이스틱
# https://programmers.co.kr/learn/courses/30/lessons/42860

def solution(name):
    answer = 999999
    name = list(name)
    temp = list("A" * len(name))
    cnt = i = 0
    while True:
        if name != temp:            
            gap = ord(name[i]) - ord(temp[i])
            if gap > 13: cnt += abs(26 - gap)
            else: cnt += gap
            temp[i] = name[i]
            print("채널변경 ", cnt)
            print(name, temp)
            if name == temp:
                if cnt < answer:
                    answer = cnt
                break
        else:
            if cnt < answer:
                answer = cnt
            break        
        cnt += 1
        i += 1
        print("리모컨이동 ", cnt)        

    temp = list("A" * len(name))
    cnt = i = 0
    while True:
        if name != temp:            
            gap = ord(name[i]) - ord(temp[i])
            if gap > 13: cnt += abs(26 - gap)
            else: cnt += gap
            temp[i] = name[i]
            print("채널변경 ", cnt)
            print(name, temp)
            if name == temp:
                if cnt < answer:
                    answer = cnt
                break
        else:
            if cnt < answer:
                answer = cnt
            break        
        cnt += 1
        i -= 1
        print("리모컨이동 ", cnt)        
    
    return answer

print(solution("ZZ"))

