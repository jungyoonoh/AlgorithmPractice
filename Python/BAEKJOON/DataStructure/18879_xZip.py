# 18879번 좌표 압축 (좌표 압축 기법) 
# https://www.acmicpc.net/problem/18879

N = int(input())
data = list(map(int, input().split()))
arr = sorted(list(set(data))) # 중복 제거 / O(1) 접근
d = dict()
for i in range(len(arr)):
    d[arr[i]] = i

for i in range(len(data)):
    print(d[data[i]], end=' ')