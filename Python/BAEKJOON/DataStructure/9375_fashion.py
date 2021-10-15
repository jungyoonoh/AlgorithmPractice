# 9375번 패션왕 신해빈 (hash) 
# https://www.acmicpc.net/problem/9375

from collections import defaultdict

T = int(input())
for _ in range(T):
    dd = defaultdict(int)
    n = int(input())
    for i in range(n):
        clothes, kind = input().split()
        dd[kind] += 1
    
    ans = 1
    for n in dd.values():
        ans *= n+1
    
    print(ans - 1)