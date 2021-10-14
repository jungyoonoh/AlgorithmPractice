# 2096번 내려가기 (DynamicProgramming) 
# https://www.acmicpc.net/problem/2096

N = int(input())

a, b, c = map(int, input().split())

maxCache = [a, b, c]
minCache = [a, b, c]

maxAns = [0, 0, 0]
minAns = [0, 0, 0]

for i in range(1, N):
    a, b, c = map(int, input().split())

    maxAns[0] = a + max(maxCache[0], maxCache[1])    
    maxAns[1] = b + max(maxCache[0], maxCache[1], maxCache[2])    
    maxAns[2] = c + max(maxCache[1], maxCache[2])
    
    minAns[0] = a + min(minCache[0], minCache[1])
    minAns[1] = b + min(minCache[0], minCache[1], minCache[2])
    minAns[2] = c + min(minCache[1], minCache[2])

    for j in range(3):
        maxCache[j] = maxAns[j]
        minCache[j] = minAns[j]
    
print(max(maxCache), min(minCache))