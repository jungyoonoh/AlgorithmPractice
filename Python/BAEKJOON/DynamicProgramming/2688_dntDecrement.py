# 2688번 줄어들지 않아 (DynamicProgramming) 
# https://www.acmicpc.net/problem/2688

TC = int(input())

for i in range(TC):
    N = int(input())
    sol = [1] * 10 
    for j in range(N):
        for k in range(10):
            sol[k] = sum(sol[k:])
    
    print(sol[0])