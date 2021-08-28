# 10988번 팰린드롬인지 확인하기 (Implementation) 
# https://www.acmicpc.net/problem/10988

str = input()
print("1" if list(str) == list(reversed(str)) else "0")