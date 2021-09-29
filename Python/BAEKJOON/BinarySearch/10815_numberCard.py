# 10815번 숫자 카드 (BinarySearch) 
# https://www.acmicpc.net/problem/10815

N = int(input())

card = list(map(int, input().split()))

M = int(input())

find = list(map(int, input().split()))

card.sort()
ans = []
for i in range(M):
    start = 0
    end = len(card) - 1
    flag = False
    while start <= end:
        mid = (start + end) // 2
        if find[i] == card[mid]:
            flag = True
            ans.append(1)
            break

        if find[i] < card[mid]:
            end = mid - 1
        elif find[i] > card[mid]:
            start = mid + 1
    
    if not flag:
        ans.append(0)

print(*ans)