# 5635번 생일 (Implementation) 
# https://www.acmicpc.net/problem/5635

N = int(input())

info = []

for i in range(N):
    name, day, month, year = input().split()
    info.append((int(year), int(month), int(day), name))

info.sort()

print(info[-1][3])
print(info[0][3])