# Simulation

# 0 1 2 3 : 북 동 남 서
# 0 1 : 육지 바다

N, M = map(int, input().split())
y, x, dir = map(int, input().split())

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

isVisited = [[0] * M for _ in range(N)]
isVisited[y][x] = 1
# 반드시 리스트 컴프리헨션을 사용해야함.
map = [list(map(int, input().split())) for _ in range(N)]

# 1. 90도 왼쪽으로 회전을 해서 갈 방향을 고른다
# 2. 만약에 거기가 가보지 않은 칸이라면, 한칸 전진하고 그렇지 않다면 회전만 한 채로 다시 1번을 수행한다
# 3. 네 방향 모두 가봤거나 바다라면 방향을 유지한 채로 한칸 뒤로 가고 1단계로 돌아간다. 이때 뒤로갔을때가 바다라면 이동을 멈춘다.

count = 1
doIt = 0
while True:
    dir = (dir + 3) % 4
    ny = y + dy[dir]
    nx = x + dx[dir]
    if isVisited[ny][nx] == 0 and map[ny][nx] == 0:
        isVisited[ny][nx] = 1
        y = ny
        x = nx
        count += 1
        doIt = 0
        continue
    else: 
        doIt += 1
    
    if doIt == 4:
        ny = y - dy[dir]
        nx = x - dx[dir]
        if map[ny][nx] == 0:
            y = ny
            x = nx
            doIt = 0
            continue
        else: break

print(count)