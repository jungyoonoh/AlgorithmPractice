# 1449번 수리공 항승  (Greedy) 
# https://www.acmicpc.net/problem/1449

N, L = map(int, input().split())
data = list(map(int, input().split()))
data.sort()

idx = 1
count = 0

for spot in data:
    if idx <= spot:
        idx = spot + L
        count += 1

print(count)