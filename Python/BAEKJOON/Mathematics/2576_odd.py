# 2576번 홀수 (Math) 
# https://www.acmicpc.net/problem/2576
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

odd = []
for i in range(7):
    num = int(input())
    if num % 2 == 1:
        odd.append(num)

if len(odd) == 0:
    print(-1)
else:
    print(sum(odd), min(odd))