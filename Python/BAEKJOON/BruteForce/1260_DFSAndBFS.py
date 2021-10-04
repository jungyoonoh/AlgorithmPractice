# 1260번 DFS와 BFS (BruteForce) 
# https://www.acmicpc.net/problem/1260

import sys
from collections import deque
sys.setrecursionlimit(10**4)
input = sys.stdin.readline
N, M, V = map(int, input().split())

graph = [[] for _ in range(N+1)] 

def dfs(board, now, isVisited, ans):
    isVisited[now] = True
    ans.append(now)
    for i in board[now]:
        if not isVisited[i]:
            dfs(board, i, isVisited, ans)

def bfs(board, now, isVisited, ans):
    dq = deque([now])
    isVisited[now] = True
    while dq:
        x = dq.popleft()
        ans.append(x)
        for i in board[x]:
            if not isVisited[i]:
                dq.append(i)
                isVisited[i] = True

    return

for i in range(M):
    start, end = map(int, input().strip().split())
    graph[start].append(end)
    graph[end].append(start)

for i in range(N + 1):
    graph[i].sort()

answer = []
isVisited = [False] * (N+1)
dfs(graph, V, isVisited, answer)
print(*answer)

answer = []
isVisited = [False] * (N+1)
bfs(graph, V, isVisited, answer)
print(*answer)
