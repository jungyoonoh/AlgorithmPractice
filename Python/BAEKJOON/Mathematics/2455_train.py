# 2455번 지능형 기차 (Math) 
# https://www.acmicpc.net/problem/2455
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

sum = 0
M = 0
for i in range(4):
    a, b = map(int, input().split())
    sum += b
    sum -= a
    M = max(sum, M)

print(M)