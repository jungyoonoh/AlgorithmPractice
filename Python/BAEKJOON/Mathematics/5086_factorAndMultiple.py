# 5086번 배수와 약수 (Math) 
# https://www.acmicpc.net/problem/5086
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0: break
    
    if b % a == 0:
        print("factor")
        continue
    
    if a % b == 0:
        print("multiple")
        continue
    
    print("neither")