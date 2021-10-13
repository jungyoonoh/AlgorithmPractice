# 1687 행렬찾기 (Implementation) 
# https://www.acmicpc.net/problem/1676

N, M = map(int, input().split()) # r c 

board = [list(map(int, input())) for _ in range(N)]
cache = [[0 for _ in range(M)] for _ in range(N)]

for i in range(M):
    if board[0][i] == 0:
        cache[0][i] = 1

for i in range(1, N):
    for j in range(M):
        cache[i][j] = cache[i-1][j] + 1 if board[i][j] == 0 else 0

st = []
ans = []
for i in range(N):
    tempH = []
    for j in range(M):
        last = j
        while st and st[-1][0] > cache[i][j]:
            h, idx = st.pop()
            tempH.append(h * (j - idx))
            last = idx
        st.append((cache[i][j], last))
    
    while st:
        h, idx = st.pop()
        tempH.append(h * (M - idx))

    # 현 라인에서 나올 수 있는 최대 행렬 사각형
    ans.append(max(tempH))

print(max(ans))