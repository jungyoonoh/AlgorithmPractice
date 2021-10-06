# 17219번 비밀번호 찾기 (dict)
# https://www.acmicpc.net/problem/17219

N, M = map(int, input().split())
d = dict()
for _ in range(N):
    site, pw = input().split()
    d[site] = pw

for _ in range(M):
    site = input().rstrip()
    print(d[site])
    