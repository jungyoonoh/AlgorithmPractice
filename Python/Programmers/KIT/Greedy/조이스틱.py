# 프로그래머스 코딩테스트 연습 > 탐욕법(Greedy) > 조이스틱
# https://programmers.co.kr/learn/courses/30/lessons/42860
# 상태) TC 한개가 안되서 못 품
# 다른 풀이를 보니 이동 후 빠꾸하는걸 고려하던데 이게 왜 그리디?
# 0914 추가) 알파벳 이동은 고정된 데이터니까, 이동의 순서만 정하면 되는 부분이었음
# 즉, 이동 방향을 그리디적 관점으로 접근

def solution(name):
    answer = 0
    minVal = len(name) - 1 # 순차로 하나씩 이동
    for i in range(len(name)):
        gap = ord(name[i]) - ord('A')
        answer += abs(26 - gap) if gap > 13 else gap 
        
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1 # A 안나올떄까지 run
        
        minVal = min(minVal, i + i + len(name) - next)
    
    answer += minVal
    return answer

print(solution("BBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB"))

