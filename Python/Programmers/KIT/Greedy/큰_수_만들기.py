# 프로그래머스 코딩테스트 연습 > 탐욕법 > 큰 수 만들기
# https://programmers.co.kr/learn/courses/30/lessons/42883

def solution(number, k):
    answer = list()
    for num in number:
        while answer and k > 0 and answer[-1] < num:
            answer.pop()
            k -= 1
        answer.append(num)
    return ''.join(answer[:len(answer) - k]) # 987654321 같은사례가 발생할 수 있음

print(solution("1924", 2))