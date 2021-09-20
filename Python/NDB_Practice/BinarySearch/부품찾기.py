# BS 
# 문제 데이터가 100만개 라는 점을 고려

N = int(input())
gear = set(map(int, input().split()))
M = int(input())
order = list(map(int, input().split()))

for i in order:
    if i in gear:
        print("yes", end=' ')
    else: print("no", end = ' ')