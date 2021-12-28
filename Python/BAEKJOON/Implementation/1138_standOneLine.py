# 1138번 한 줄로 서기 (Implementation) 
# https://www.acmicpc.net/problem/1138

N = int(input())
standInfo = list(map(int, input().split()))
ans = [-1] * N
for i in range(1, N+1): # 1 ~ N
    cnt = 0
    for j in range(N):
        # 이미 들어있는 애들은 나보다 작다 & 뛰어넘은 빈칸은 나보다 큰 애들이 들어올 개수
        if standInfo[i - 1] == cnt and ans[j] == -1:
            ans[j] = i
            break
        elif ans[j] == -1:
            cnt += 1

print(*ans)