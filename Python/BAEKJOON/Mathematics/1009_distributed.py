# 1009번 분산처리 (Math) 
# https://www.acmicpc.net/problem/1009
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

T = int(input())

for i in range(T):
    cycle = 1
    a, b = map(int, input().split())
    digit = a % 10
    res = digit
    while True:
        res = (res * digit) % 10
        if res == digit: break
        cycle += 1
        
    idx = (b-1) % cycle
    res = digit
    for i in range(idx):
        res = (res * digit) % 10
    
    print(res if res != 0 else 10)