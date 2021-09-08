# 1764번 듣보잡 (String) 
# https://www.acmicpc.net/problem/1764
# 듣보잡이 영어로 뭘까요

N, M = map(int, input().split());

A = set()
B = set()
for _ in range(N):
    A.add(input())

for _ in range(M):
    B.add(input())

C = sorted(list(A & B)) # 정렬

print(len(C))
for i in range(len(C)):
    print(C[i])