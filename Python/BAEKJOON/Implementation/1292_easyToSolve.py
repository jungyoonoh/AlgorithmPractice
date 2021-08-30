# 1292번 쉽게 푸는 문제 (Implementation) 
# https://www.acmicpc.net/problem/1292

A, B = map(int, input().split())

table = []
num = 1
for i in range(1, 1001):
    if i > num * (num + 1) / 2:
        num += 1
    table.append(num)
sum = 0
for i in range(A - 1, B):
    sum += table[i]

print(sum)
