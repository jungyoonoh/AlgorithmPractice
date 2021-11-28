# 1747번 소수 & 팰린드롬 (BruteForce) 
# https://www.acmicpc.net/problem/1747

N = int(input())

M = 1_003_002

prime = [1] * M

for i in range(2, M):
    if prime[i] == 0: continue
    
    for i in range(2*i, M, i):
        prime[i] = 0
        
for i in range(N, M):
    if i == 1: continue
    if prime[i] == 1:
        numToString = str(i)
        if numToString == numToString[::-1]:
            print(i)
            break