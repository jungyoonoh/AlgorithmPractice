# Greedy Algorithm
N, M, K = map(int, input().split())

data = list(map(int, input().split()))

data.sort()
first = data[-1]
second = data[-2]

sol = 0

# 일반적인 방법으로 구하기
while True:
    for i in range(K):
        if M == 0: break
        sol += first
        M -= 1
    if M == 0: break
    sol += second
    M -= 1
print(sol)
    
# 연산으로 구하기
count = int(M / (K+1)) * K
count += M % (K+1)

sum = 0
sum += count * first
sum += (M - count) * second
print(sum)
