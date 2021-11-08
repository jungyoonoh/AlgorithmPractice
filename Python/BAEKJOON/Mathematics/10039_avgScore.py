# 10039번 평균 점수 (Math) 
# https://www.acmicpc.net/problem/10039
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

L = []
for i in range(5):
    num = int(input())
    L.append(num if num > 40 else 40)

print(sum(L) // 5)