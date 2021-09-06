# 15903번 카드 합체 놀이 (Greedy) 
# https://www.acmicpc.net/problem/15903

N = int(input())
data = list(map(int, input().split()))
data.sort()
print(data[(N-1) // 2])
