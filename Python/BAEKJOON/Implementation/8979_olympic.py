# 8979번 올림픽 (Implementation) 
# https://www.acmicpc.net/problem/8979

import sys
input = sys.stdin.readline
N, K = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(N)]

sortedData = sorted(data, key = lambda x : (x[1], x[2], x[3]), reverse=True)

rank = [[1, sortedData[0][0]], ]
for i in range(1, N):
    if sortedData[i - 1][1] == sortedData[i][1] and sortedData[i - 1][2] == sortedData[i][2] and sortedData[i - 1][3] == sortedData[i][3]:
        rank.append([rank[i - 1][0], sortedData[i][0]])
    else: rank.append([i+1, sortedData[i][0]])

for i in range(len(rank)):
    if rank[i][1] == K:
        print(rank[i][0])
        break