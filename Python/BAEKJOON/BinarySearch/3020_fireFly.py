# 3020번 개똥벌레 (BinarySearch) 
# https://www.acmicpc.net/problem/3020

# 짝수번째가 석순 홀수번째는 종유석, 종유석은 누적합에서 끝을 고려해주지 않아도 됨 석순만 끝 고려
import itertools

N, H = map(int, input().split())

mark = [0] * H

for i in range(N):
    data = int(input())
    if i % 2 == 0:
        mark[0] += 1
        mark[data] -= 1
    else:
        mark[H - data] += 1

accSum = list(itertools.accumulate(mark))
minDestroy = min(accSum)
dirCnt = accSum.count(minDestroy)
print(minDestroy, dirCnt)
