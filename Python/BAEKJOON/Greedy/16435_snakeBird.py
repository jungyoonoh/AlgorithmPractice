# 16435번 스네이크버드 (Greedy) 
# https://www.acmicpc.net/problem/16435

N, L = map(int, input().split())

tree = list(map(int, input().split()))

tree.sort()

for i in range(N):
    if tree[i] <= L:
        L += 1
    else: break

print(L)