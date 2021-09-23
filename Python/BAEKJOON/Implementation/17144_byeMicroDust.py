# 17144번 미세먼지 안녕! (Implementation) 
# https://www.acmicpc.net/problem/17144

def spread():
    global R,C
    tempBoard = [[0 for _ in range(C)] for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if board[i][j] < 5: continue
            cnt = 0
            spreadAmount = board[i][j] // 5
            for k in range(4):
                ny = i + dy[k]
                nx = j + dx[k]
                if ny < 0 or nx < 0 or ny >= R or nx >= C or board[ny][nx] == -1:
                    continue
                tempBoard[ny][nx] += spreadAmount
                cnt += 1
            board[i][j] -= spreadAmount * cnt
    
    for i in range(R):
        for j in range(C):
            board[i][j] += tempBoard[i][j]

    return 0

def wind():

    # 반시계 바람 -> 진행은 시계로 9 12 3 6 순
    for i in range(cleanerUp - 2, -1, -1):
        board[i+1][0] = board[i][0]
    
    for i in range(1, C):
        board[0][i-1] = board[0][i]
    
    for i in range(1, cleanerUp + 1):
        board[i-1][C-1] = board[i][C-1]
    
    for i in range(C-2, 0, -1):
        board[cleanerUp][i+1] = board[cleanerUp][i]
    board[cleanerUp][1] = 0

    # 시계 바람 -> 진행은 반시계로 9 6 3 12 순
    for i in range(cleanerDown + 2, R):
        board[i - 1][0] = board[i][0]
    
    for i in range(1, C):
        board[R-1][i-1] = board[R-1][i]
    
    for i in range(R-2, cleanerDown - 1, -1):
        board[i+1][C-1] = board[i][C-1]
    
    for i in range(C-2, 0, -1):
        board[cleanerDown][i+1] = board[cleanerDown][i]
    board[cleanerDown][1] = 0

    return 0


R,C,T = map(int,input().split())

dy = [-1, 0, 1, 0] # 위 오 아 왼
dx = [0, 1, 0, -1]

board = [list(map(int, input().strip().split())) for _ in range(R)]
cleanerUp = cleanerDown = -1
for i in range(R):
    if -1 in board[i]:
        cleanerUp = i
        cleanerDown = i+1
        break

for _ in range(T):
    spread()
    wind()

ans = 0
for i in range(R):
    ans += sum(board[i])

print(ans + 2)