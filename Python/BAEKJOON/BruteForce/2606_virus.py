# 2606번 바이러스 (BruteForce) 
# https://www.acmicpc.net/problem/2606

import sys

sys.setrecursionlimit(10**4 + 1)

N = int(input())
M = int(input())

def spread(now):
    isVisited[now] = True
    for node in network[now]:
        if not isVisited[node]:
            spread(node)

isVisited = [False] * (N + 1)
network = [[] for _ in range(N + 1)]

for i in range(M):
    start, end = map(int, input().split())
    network[start].append(end)
    network[end].append(start)

spread(1)
ans = 0
for i in range(2, N + 1):
    if isVisited[i]:
        ans += 1

print(ans)