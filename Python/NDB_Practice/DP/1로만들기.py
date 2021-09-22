# DP
# 주어진 숫자가 1이 되는 횟수.
# 역으로 1이 주어진 숫자가 되는 과정을 파악

X = int(input())

cache = [0] * 30001

# 순차적으로 발생할 수 있는 경우의 수를 갱신
for i in range(2, X + 1):
    cache[i] = cache[i-1] + 1

    if i % 2 == 0:
        cache[i] = min(cache[i], cache[i // 2] + 1) 
    
    if i % 3 == 0:
        cache[i] = min(cache[i], cache[i // 3] + 1)
    
    if i % 5 == 0:
        cache[i] = min(cache[i], cache[i // 5] + 1)

print(cache[X])