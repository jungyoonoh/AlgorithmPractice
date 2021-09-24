# 11866번 요세푸스 문제 (queue) 
# https://www.acmicpc.net/problem/11866

from collections import deque

N, K = map(int, input().split())
dq = deque()

for i in range(N):
    dq.append(i+1)

permutation = []
while dq:
    for _ in range(K - 1):
        dq.append(dq.popleft())
    permutation.append(str(dq.popleft()))

ans = ', '.join(permutation)
ans = '<' + ans + '>'
print(ans)