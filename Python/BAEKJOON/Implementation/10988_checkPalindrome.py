# 10988번 팰린드롬인지 확인하기 (Implementation) 
# https://www.acmicpc.net/problem/10988

str = input()
print("1" if str == str[::-1] else "0") # 둘다 가능하다 (리스트 슬라이싱 이용)
print("1" if list(str) == list(reversed(str)) else "0") # 속도의 차이는 없다 (내장 함수 이용)