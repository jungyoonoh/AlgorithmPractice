# 6443번 애너그램 (BruteForce) 
# https://www.acmicpc.net/problem/6443

# 메모리 초과 코드
# import sys
# import itertools

# input = sys.stdin.readline

# N = int(input())

# for i in range(N):
#     s = input().strip()
#     per = list(itertools.permutations(s, len(s)))
#     per.sort()
#     pool = set()
#     for element in per:
#         if element not in pool:
#             pool.add(element)
#             print(''.join(element))

import sys 
from collections import defaultdict

input = sys.stdin.readline
dd = defaultdict(int)
def find(L, cnt, anagram):
    if cnt == L:
        ans = ''.join(anagram)
        print(ans)
        return
    
    for i in dd.keys():
        if dd[i] > 0:
            anagram.append(i)
            dd[i] -= 1
            find(L, cnt+1, anagram)
            anagram.pop()
            dd[i] += 1
            
    return 

N = int(input())

for i in range(N):
    S = input().strip()
    stl = list(S)
    stl.sort()
    for i in stl:
        dd[i] += 1
    find(len(stl), 0, [])
    dd.clear()