# 12904번 A와 B (String) 
# https://www.acmicpc.net/problem/12904

S = input().strip()
T = input().strip()

flag = False
while True:
    if len(S) == len(T):
        if S == T:
            flag = True
        break
    
    last = T[-1]
    T = T[:-1]
    if last == 'B':
        T = T[::-1]
        
print(1 if flag else 0)