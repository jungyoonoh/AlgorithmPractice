# 5565번 영수증 (Implementation) 
# https://www.acmicpc.net/problem/5565

total = int(input())

price = 0
for i in range(9):
    a = int(input())
    price += a

print(total - price)