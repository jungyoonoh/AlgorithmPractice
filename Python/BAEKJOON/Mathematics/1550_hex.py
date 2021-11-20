# 1550번 16진수 (Math) 
# https://www.acmicpc.net/problem/1550

N = input()

S = 0
for i in range(len(N)):
    if ord(N[i]) - ord('A') >= 0:
        S += (ord(N[i]) - ord('A') + 10) * (16 ** (len(N) -  1 - i))
        continue
    S += int(N[i]) * (16 ** (len(N) -  1 - i))

print(S)