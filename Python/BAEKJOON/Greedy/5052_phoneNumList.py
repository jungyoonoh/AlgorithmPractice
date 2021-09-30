# 5052번 전화번호 목록 (Greedy) 
# https://www.acmicpc.net/problem/5052

import sys
input = sys.stdin.readline

TC = int(input())

for _ in range(TC):
    t = int(input())
    phoneList = []
    for _ in range(t):
        phone = str(input().strip())
        phoneList.append(phone)
    phoneList.sort()
    flag = True
    for i in range(len(phoneList) - 1):
        M = min(len(phoneList[i]), len(phoneList[i+1]))
        if phoneList[i][:M] == phoneList[i+1][:M]:
            flag = False
            break
    
    print("YES" if flag == True else "NO")
