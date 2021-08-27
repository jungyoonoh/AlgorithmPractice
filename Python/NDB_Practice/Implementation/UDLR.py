# Simulation

N = int(input())

command = input().split()

dx = [0,1,0,-1]
dy = [1,0,-1,0]

mv = ['R', 'D', 'L', 'U'] # RDLU
x = 1
y = 1

for dir in command:
    for i in range(len(mv)):
        if dir == mv[i]:
            nx, ny = x + dx[i], y + dy[i]
    
    if nx < 1 or nx > N or ny < 1 or ny > N:
        continue
    
    x, y = nx, ny

print(x, y)