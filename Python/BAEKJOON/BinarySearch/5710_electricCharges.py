# 5710번 전기요금 (BinarySearch) 
# https://www.acmicpc.net/problem/5710

import sys
input = sys.stdin.readline

def getElectric(c):
    electric = 0
    if c <= 100 * 2:
        electric = c // 2
    elif c <= 100 * 2 + 9900 * 3:
        electric = 100 + (c - 200) // 3
    elif c <= 100 * 2 + 9900 * 3 + 990000 * 5:
        electric = 10000 + (c - 29900) // 5
    else:
        electric = 1000000 + (c - 4979900) // 7
    return electric

def getCharges(c):
    charges = 0
    if c <= 100:
        charges = c * 2
    elif c <= 10000:
        charges = (100 * 2) + (c - 100) * 3
    elif c <= 1000000:
        charges = (100 * 2) + (9900 * 3) + (c - 10000) * 5
    else:
        charges = (100 * 2) + (9900 * 3) + (990000 * 5) + (c - 1000000) * 7

    return charges


while True:
    A, B = map(int, input().split())
    if A == 0 and B == 0: break
    totalUse = getElectric(A)
    start, end = 0, totalUse
    # x가 상근이 y가 이웃
    x = y = 0
    while start <= end:
        mid = (start + end) // 2
        x, y = mid, totalUse - mid
        xCharges = getCharges(x)
        yCharges = getCharges(y)
        diff = yCharges - xCharges
        if diff == B:
            print(xCharges)
            break
        elif diff > B: start = mid + 1
        else: end = mid - 1
