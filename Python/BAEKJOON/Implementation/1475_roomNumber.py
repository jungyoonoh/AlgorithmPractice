# 1475 방번호 (Implementation) 
# https://www.acmicpc.net/problem/1475
# 예전에 C++로 풀었던게 재채점 되어버림

N = input()
ans = [0] * 10
sixNine = 0
for i in range(len(N)):
    if N[i] == '6' or N[i] == '9':
        sixNine += 1
        continue
    ans[int(N[i])] += 1

print(max(sixNine // 2 + sixNine % 2, max(ans)))