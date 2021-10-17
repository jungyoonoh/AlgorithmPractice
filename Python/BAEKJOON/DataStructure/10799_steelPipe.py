# 10799번 쇠막대기 (Stack)
# https://www.acmicpc.net/problem/10799

data = input()
pipe = 0
ans = 0
for i in range(len(data)):
    if data[i] == '(':
        pipe += 1
    elif data[i] == ')' and data[i-1] == '(':
        pipe -= 1
        ans += pipe
    else:
        pipe -= 1
        ans += 1

print(ans)