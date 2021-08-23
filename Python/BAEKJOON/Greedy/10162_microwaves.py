# 10162번 전자레인지 (Greedy) 
# https://www.acmicpc.net/problem/10162
T = int(input())

ans = list()

timer_list = [300, 60, 10]

if T % 10 != 0:
    print("-1")
else:
    for i, time in enumerate(timer_list):
        ans.append(T // time)
        T %= time
    print(ans[0], ans[1], ans[2])

