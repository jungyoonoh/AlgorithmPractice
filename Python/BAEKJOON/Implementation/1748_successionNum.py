# 1748번 수 이어 쓰기 1 (Implementation) 
# https://www.acmicpc.net/problem/1748

N = int(input())

count = 0
i = 1
while True:
    if N >= (10 ** i):
        count += 9 * (10 ** (i-1)) * i
    else:
        count += (N - (10 ** (i-1)) + 1) * i
        break
    i += 1

print(count)