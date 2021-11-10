# 13549번 숨바꼭질3 (BruteForce) 
# https://www.acmicpc.net/problem/13549

from collections import deque

N, K = map(int, input().split())

dq = deque()
dq.append(N)
size = 100001
time = [0] * size
isVisited = [False] * size
isVisited[N] = True

while dq:
    x = dq.popleft()
    
    if x*2 < size and not isVisited[x*2]:
        dq.appendleft(x*2)
        isVisited[x*2] = True
        time[x*2] = time[x]
    
    if x+1 < size and not isVisited[x+1]:
        dq.append(x+1)
        isVisited[x+1] = True
        time[x+1] = time[x] + 1
    
    if x-1 >= 0 and not isVisited[x-1]:
        dq.append(x-1)
        isVisited[x-1] = True
        time[x-1] = time[x] + 1
            
print(time[K])