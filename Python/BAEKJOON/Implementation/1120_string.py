# 1120번 문자열 (Implementation) 
# https://www.acmicpc.net/problem/1120

A, B = input().split()
ans = []
for i in range(len(B) - len(A) + 1):
    count = 0
    for j in range(len(A)):
        if A[j] != B[i + j]:
            count += 1
    ans.append(count)

print(min(ans))