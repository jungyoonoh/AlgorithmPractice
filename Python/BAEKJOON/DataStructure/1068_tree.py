# 1068번 트리 (Tree) 
# https://www.acmicpc.net/problem/1068

N = int(input())
info = list(map(int, input().split()))
K = int(input())
def cut(k):
    info[k] = -2
    for i in range(len(info)):
        if info[i] == k:
            cut(i)

cut(K)

cnt = 0
for i in range(len(info)):
    if info[i] != -2 and i not in info:
        cnt += 1

print(cnt)