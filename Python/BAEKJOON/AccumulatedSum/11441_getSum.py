# 11441번 합 구하기 (AccumulatedSum) 
# https://www.acmicpc.net/problem/11441

import itertools
import sys

input = sys.stdin.readline

N = int(input())

data = list(map(int, input().split()))
accumulatedSum = list(itertools.accumulate(data))
accumulatedSum.insert(0,0)
M = int(input())

for i in range(M):
    start, end = map(int, input().split())
    print(accumulatedSum[end] - accumulatedSum[start - 1])
