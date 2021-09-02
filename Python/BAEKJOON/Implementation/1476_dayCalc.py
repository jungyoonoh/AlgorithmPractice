# 1476 날짜 계산 (Implementation) 
# https://www.acmicpc.net/problem/1476
# 중국인의 나머지 정리

E, S, M = map(int, input().split())
year = 1
while True:
    if (year - E) % 15 == 0 and (year - S) % 28 == 0 and (year - M) % 19 == 0:
        break
    year += 1

print(year)