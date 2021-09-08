# 10610번 30 (String) 
# https://www.acmicpc.net/problem/10610

num = input()
check = True
if '0' in num: # 만들 수 있는 숫자가 10으로 나눌 수 있다면
    num = sorted(list(num), reverse=True)
    s = int(''.join(num))
    if s % 3 != 0: 
        check = False
else: check = False

print(''.join(num) if check else -1)