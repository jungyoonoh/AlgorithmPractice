# 7490번 0 만들기 (BruteForce) 
# https://www.acmicpc.net/problem/7490

ans = []
def do(equation, cnt, N):
    if cnt == N:
        equation.append(str(cnt))
        tempEquation = [i.replace(' ', '') for i in equation]
        equationToStr = ''.join(tempEquation)
        if eval(equationToStr) == 0:
            ans.append(''.join(equation))
        equation.pop()
        return
    
    for operation in ['+', '-', ' ']:
        equation.append(str(cnt))
        equation.append(operation)
        do(equation, cnt+1, N)
        equation.pop()
        equation.pop()

TC = int(input())

for i in range(TC):
    N = int(input())
    do([], 1, N)
    ans.sort()
    for equation in ans:
        print(equation)
    if i != TC - 1:
        print()
    while ans:
        ans.pop()