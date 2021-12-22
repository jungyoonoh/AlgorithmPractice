# 1662번 압축 (stack) 
# https://www.acmicpc.net/problem/1662

s = input().strip()
stack = []
length = 0
multiple = ''
for c in s:
    if c.isdigit():
        length += 1
        multiple = c
    elif c == '(':
        stack.append((multiple, length - 1))
        length = 0
    else:
        mul, pre = stack.pop()
        length = (int(mul) * length) + pre

print(length)