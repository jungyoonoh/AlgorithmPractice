# Simulation

spot = input()
y = int(ord(spot[0])) - int(ord('a')) + 1 # a 
x = int(spot[1]) # 1

# 12시부터 시계
dy = [-2, -1, 1, 2, 2, 1, -1, -2]
dx = [1, 2, 2, 1, -1, -2, -2, -1]
ans = 0
for i in range(len(dx)):
    ny = y + dy[i]
    nx = x + dx[i]
    if ny >= 1 and ny <= 8 and nx >= 1 and nx <= 8:
        ans += 1
print(ans)
