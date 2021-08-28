# 2847번 게임을 만든 동준이 (Greedy) 
# https://www.acmicpc.net/problem/2847

# 공부할 것
# reversed vs reverse
# sorted vs sort

N = int(input())

data = []
for _ in range(N):
    data.append(int(input()))

data.reverse()
move = 0
for i in range(len(data) - 1):
    if data[i] <= data[i+1]:
        move += data[i+1] - data[i] + 1
        data[i+1] = data[i] - 1

print(move) 