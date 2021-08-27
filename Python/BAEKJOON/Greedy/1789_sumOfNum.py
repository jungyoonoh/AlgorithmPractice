# 1789번 수들의 합 (Greedy) 
# https://www.acmicpc.net/problem/1789

S = int(input())
start = 1
end = 4294967295
sum = 0
ans = -1
while start <= end:
    mid = (start + end) // 2
    sum = (mid + 1) * mid // 2
    if sum <= S:
        start = mid + 1
        ans = max(ans, mid)
    else: 
        end = mid - 1

print(ans)