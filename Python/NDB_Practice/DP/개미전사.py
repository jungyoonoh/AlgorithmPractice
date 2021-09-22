# DP
# 최소 1칸 이상을 띄어야함. 
# 현재 칸을 건너뛸건지 아닌지 판단

N = int(input())
data = list(map(int, input().split()))
get = [0] * N
get[0] = data[0]
get[1] = max(data[0], data[1])
for i in range(2, N):
    get[i] = max(get[i - 1], get[i - 2] + data[i])

print(get[N-1])