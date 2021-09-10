# 프로그래머스 코딩테스트 연습 > 해시 > 전화번호 목록
# https://programmers.co.kr/learn/courses/30/lessons/42577

def solution(phone_book):
    answer = True
    phone_book = sorted(phone_book)
    for i in range(len(phone_book) - 1):
        if phone_book[i] == phone_book[i+1][:len(phone_book[i])]:
            answer = False
            break

    return answer

print(solution(["119", "97674223", "1195524421"]))
