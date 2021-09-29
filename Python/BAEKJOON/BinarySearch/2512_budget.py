# 10815번 숫자 카드 (BinarySearch) 
# https://www.acmicpc.net/problem/10815

N = int(input())

budget = list(map(int, input().split()))

limit = int(input())

start = 0
end = limit
if sum(budget) <= limit:
    print(max(budget))
else: 
    while start <= end:
        mid = (start + end) // 2
        sum = 0
        for i in range(len(budget)):
            sum += mid if mid < budget[i] else budget[i]
        
        if sum <= limit:
            ans = mid
            start = mid + 1
        else:
            end = mid - 1
    print(ans)
