# 2810번 컵홀더  (Greedy) 
# https://www.acmicpc.net/problem/2810

N = int(input())
str = input()

count = str.count('LL')
print(N if count <= 1 else N - count + 1)