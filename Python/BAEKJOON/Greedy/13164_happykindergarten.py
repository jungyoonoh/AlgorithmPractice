# 13164번 행복 유치원 (Greedy) 
# https://www.acmicpc.net/problem/13164

N, K = map(int, input().split())
height = list(map(int, input().split()))

height.sort()

diff = []
for i in range(1, N):
    diff.append(height[i] - height[i-1])

diff.sort()

ans = 0

for i in range(N-K):
    ans += diff[i]

print(ans)