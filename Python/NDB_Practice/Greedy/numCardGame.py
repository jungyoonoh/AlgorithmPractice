# Greedy Algorithm
N, M = map(int, input().split())

ans = 0
for i in range(N):
    data = list(map(int, input().split()))
    minInList = min(data)
    ans = max(ans, minInList)

print(ans)