# 2525번 오븐 시계 (Math) 
# https://www.acmicpc.net/problem/2525
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

h, m = map(int, input().split())
time = int(input())
m += time
h += m // 60
m %= 60
h %= 24
print(h, m)