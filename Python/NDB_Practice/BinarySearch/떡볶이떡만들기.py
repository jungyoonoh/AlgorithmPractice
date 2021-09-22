# BS 
# 문제 데이터가 20억이라는 점을 고려

N, M = map(int, input().split())
d = list(map(int, input().split()))

start, end = 0, max(d)
ans = start
while start <= end:
    sell = 0
    mid = (start + end) // 2

    for i in range(len(d)):
        if d[i] > mid:
            sell += d[i] - mid
    
    if sell >= M:
        start = mid + 1
        ans = mid
    else:
        end = mid - 1

print(ans)