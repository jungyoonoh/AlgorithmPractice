# 18310번 안테나 (Greedy) 
# https://www.acmicpc.net/problem/18310

N = int(input())
data = list(map(int, input().split()))
data.sort()
print(data[(N-1) // 2])
