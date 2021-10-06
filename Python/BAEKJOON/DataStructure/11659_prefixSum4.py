# 11659번 구간 합 구하기 4 (prefixSum) 
# https://www.acmicpc.net/problem/11659

import itertools
import sys

input = sys.stdin.readline

N, M = map(int, input().split())

data = list(map(int, input().split()))

prefixSum = list(itertools.accumulate(data))
prefixSum.insert(0,0)
for i in range(M):
    start, end = map(int, input().split())
    print(prefixSum[end] - prefixSum[start - 1])