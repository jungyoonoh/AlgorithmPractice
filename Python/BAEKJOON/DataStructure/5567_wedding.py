# 5567번 결혼식 (graph) 
# https://www.acmicpc.net/problem/5567

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

s = set()
for i in graph[1]:
    s.add(i)
    if len(graph[i]) > 0:
        for j in graph[i]:
            s.add(j)

if 1 in s:
    s.remove(1)
print(len(list(s)))