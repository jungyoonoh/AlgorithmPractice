# 5543번 상근날드 (Math) 
# https://www.acmicpc.net/problem/5543
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

burger = []
drink = []

for i in range(3):
    burger.append(int(input()))
    
for i in range(2):
    drink.append(int(input()))
    
print(min(burger) + min(drink) - 50)