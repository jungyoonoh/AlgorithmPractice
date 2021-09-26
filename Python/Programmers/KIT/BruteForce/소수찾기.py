# 프로그래머스 코딩테스트 연습 > 완전탐색 > 소수찾기
# https://programmers.co.kr/learn/courses/30/lessons/42839

import math

isIncluded = [False] * 7

board = [False] * 9999999

def isPrime(num):
    num = int(num)
    if num == 0 or num == 1: return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0: return False
    board[num] = True
    return True

def isOverlap(num):
    num = int(num)
    if board[num]: return True
    return False

def do(primeList, now, next):
    global answer
    if next - 1 == len(primeList): return
    
    if len(now) != 0:
        s = ''.join(str(s) for s in now)
        if not isOverlap(s) and isPrime(s):
            answer += 1

    for i in range(len(primeList)):
        if not isIncluded[i]:
            isIncluded[i] = True
            now.append(primeList[i])
            do(primeList, now, next + 1)
            now.pop()
            isIncluded[i] = False

answer = 0
def solution(numbers):
    # 1자리 ~ n자리 까지 소수 판별
    primeList = list(map(int, numbers))
    do(primeList, [], 0)

    return answer

print(solution("011"))