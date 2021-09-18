# 1967번 트리의 지름 (Tree) 
# https://www.acmicpc.net/problem/1967

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4 + 1)
def solution(tree, start, now, isVisited):
    global dist, M
    if start != now and len(tree[now]) == 1:
        M = max(M, dist)
        return 
    isVisited[now] = True
    for info in tree[now]:
        if not isVisited[info[0]]:
            dist += info[1]
            solution(tree, start, info[0], isVisited)
            dist -= info[1]


N = int(input())
tree = [[] for _ in range(N + 1)]

for i in range(N - 1):
    parent, child, weight = map(int, input().strip().split())
    tree[parent].append((child, weight))
    tree[child].append((parent, weight))

M = 0
for i in range(1, N + 1):
    if len(tree[i]) == 1: # leaf
        dist = 0
        isVisited = [False] * (N+1)
        solution(tree, i, i, isVisited)

print(M)