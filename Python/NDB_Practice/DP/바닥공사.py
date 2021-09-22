# DP
# 그림을 그려보면 점화식을 뽑아낼 수 있다

N = int(input())

dp = [0] * N
dp[0], dp[1] = 1, 3

for i in range(2, N):
    dp[i] = (dp[i-1] + dp[i-2] * 2) % 796796

print(dp[N-1])