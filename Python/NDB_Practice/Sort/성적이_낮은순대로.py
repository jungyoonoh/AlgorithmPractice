# Sort

N = int(input())
data = []
for i in range(N):
    temp = input().split()
    data.append((temp[0], int(temp[1])))
    
data = sorted(data, key=lambda obj:obj[1])

for i in range(N):
    print(data[i][0], end=' ')