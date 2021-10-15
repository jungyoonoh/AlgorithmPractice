# 16236번 아기상어 (Simulation) 
# https://www.acmicpc.net/problem/16236

# 1 ~ 6 물고기의 크기, 아기상어는 처음에 2, 자기보다 작은건 먹을수 ok 같은건 지나가기 ok, 먹지는 x 
# 크기 증가는 무게만큼 먹어야함 처음에 2니까 2짜리 물고기 2개 먹어야하고 그다음은 3짜리 3개 그 다음은 4짜리 4개 순

from collections import deque

N = int(input())

board = [[] for _ in range(N)]

# 1트 : 위 왼 오 아 순으로 봐야.. (먹을 수 있는 물고기가 많다면 가장 좌상단이 우선순위, 그 다음은 같은 선상)
# 2트 : -> 이 부분이 잘못된 것이었음. 반례 존재

dy = [-1, 0, 0, 1]
dx = [0, -1, 1, 0]

sharkX = sharkY = -1
babySize = 2
feedCnt = 0
ans = 0
for i in range(N):
    line = list(map(int, input().split()))
    if 9 in line:
        sharkY, sharkX = i, line.index(9)
    board[i].extend(line)


while True:
    q = deque([(sharkY, sharkX, 0)]) # y, x, time
    isVisited = [[False for _ in range(N)] for _ in range(N)]
    isVisited[sharkY][sharkX] = True
    flag = 401

    sharkCanFeedList = []

    while q:
        y, x, time = q.popleft()

        if time > flag:
            continue

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or nx < 0 or ny >= N or nx >= N:
                continue

            if isVisited[ny][nx] or board[ny][nx] > babySize:
                continue
            
            if board[ny][nx] != 0 and board[ny][nx] < babySize:
                sharkCanFeedList.append((ny, nx, time+1))
                flag = time

            isVisited[ny][nx] = True
            q.append((ny, nx, time+1))

    if len(sharkCanFeedList) > 0:
        sharkCanFeedList.sort()
        y, x, time = sharkCanFeedList[0][0], sharkCanFeedList[0][1], sharkCanFeedList[0][2] 

        # feed
        feedCnt += 1
        ans += time
        if feedCnt == babySize:
            babySize += 1
            feedCnt = 0
        
        # 위치 갱신
        board[sharkY][sharkX] = 0
        board[y][x] = 9
        sharkY, sharkX = y, x 
    else: 
        break

print(ans)