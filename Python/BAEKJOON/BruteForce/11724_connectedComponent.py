# 11724번 연결 요소의 개수 (BruteForce) 
# https://www.acmicpc.net/problem/11724

N, M = map(int, input().split())

def find(now):
    isVisited[now] = True
    for node in graph[now]:
        if not isVisited[node]:
            find(node)


isVisited = [False] * (N+1)
graph = [[] for _ in range(N + 1)]

for i in range(M):
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)

ans = 0
for i in range(1, N+1):
    if not isVisited[i]:
        find(i)
        ans += 1

print(ans)