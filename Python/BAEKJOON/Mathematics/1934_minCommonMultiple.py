# 1934번 최소공배수 (Math) 
# https://www.acmicpc.net/problem/1934
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

N = int(input())

for i in range(N):
    a, b = map(int, input().split())
    n1, n2 = a, b
    while b != 0:
        r = a % b
        a = b
        b = r
    
    print(int((n1 * n2) / a))