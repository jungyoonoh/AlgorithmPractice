# 1764번 듣보잡 (String) 
# https://www.acmicpc.net/problem/1764
# 듣보잡이 영어로 뭘까요

import sys
input = sys.stdin.readline;
N, M = map(int, input().split());

A = set()
B = set()
ans = []
for _ in range(N):
    A.add(input().rstrip())

for _ in range(M):
    B.add(input().rstrip())

C = A & B
C = list(C)
print(len(C))
for i in range(len(C)):
    print(C[i])