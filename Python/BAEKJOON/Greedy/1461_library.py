# 1461번 도서관 (Greedy) 
# https://www.acmicpc.net/problem/1461

N, M = map(int, input().split())
book = list(map(int, input().split()))

left = []
right = [] # 책 무더기 기준

for i in book:
    if i < 0:
        left.append(abs(i))
    else: 
        right.append(i)

left.sort(reverse=True)
right.sort(reverse=True)

ans = []

for i in range(0, len(left), M):
    ans.append(left[i])

for i in range(0, len(right), M):
    ans.append(right[i])

ans.sort()
step = 0
step += ans.pop()
for i in ans:
    step += i * 2

print(step)