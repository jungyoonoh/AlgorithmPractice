# 1167번 트리의 지름 (Tree) 
# https://www.acmicpc.net/problem/1167

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5 + 1)

V = int(input())

tree = [[] for _ in range(V + 1)]

def find(now, dist):
    for node in tree[now]:
        if dist[node[0]] == 0:
            dist[node[0]] += dist[now] + node[1]
            find(node[0], dist)

    return

for _ in range(V):
    data = list(map(int, input().strip().split()))
    node = data[0]
    info = data[1:]
    while len(info) > 1:
        tree[node].append((info[0], info[1]))
        del info[0]
        del info[0]

dist = [0] * (V + 1)
find(1, dist)
dist[1] = 0

spot = maxVal = -1
for i in range(len(dist)):
    if maxVal < dist[i]:
        maxVal = dist[i]
        spot = i

dist = [0] * (V + 1)
find(spot, dist)
dist[spot] = 0

print(max(dist))