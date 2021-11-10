# 13913번 숨바꼭질4 (BruteForce) 
# https://www.acmicpc.net/problem/13913

from collections import deque

N, K = map(int, input().split())

size = 100001
move = [0] * size
isVisited = [False] * size
dq = deque()
dq.append(N)
time = [0] * size
while dq:
    x = dq.popleft()
    
    if x == K:
        ans = deque()
        ans.appendleft(x)
        now = x
        print(time[K])
        for _ in range(time[K]):
            parent = move[now]            
            ans.appendleft(parent)
            now = parent
        print(*ans)           
        break
    
    for nx in (x-1, x+1, x*2):
        if nx < 0 or nx >= size or isVisited[nx]:
            continue
        
        isVisited[nx] = True
        dq.append(nx)
        time[nx] = time[x] + 1
        move[nx] = x
