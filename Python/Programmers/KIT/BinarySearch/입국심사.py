# 프로그래머스 코딩테스트 연습 > 이분탐색 > 입국심사
# https://programmers.co.kr/learn/courses/30/lessons/43238

def solution(n, times):
    answer = 0
    
    start = 0
    end = 1_000_000_000 * max(times)
    
    while start <= end:
        mid = (start + end) // 2
        total = 0
        for i in range(len(times)):
            total += mid // times[i]

        if total < n: 
            start = mid + 1
        else:
            end = mid - 1
            
    answer = start

    return answer