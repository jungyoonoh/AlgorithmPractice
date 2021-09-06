# 15904번 UCPC는 무엇의 약자일까? (Greedy) 
# https://www.acmicpc.net/problem/15904

data = list(input())

UCPC = ['U', 'C', 'P', 'C']

count = 0
for obj in data:
    if count == 4: break
    for i in range(count, 4):
        if UCPC[i] in obj:
            count += 1
        else: break

print("I love UCPC" if count == 4 else "I hate UCPC")