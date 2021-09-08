# 11656번 접미사 배열 (String) 
# https://www.acmicpc.net/problem/11656

data = input()

suffix = []
for i in range(len(data)):
    suffix.append(data[i:len(data)])

suffix.sort()

for i in range(len(data)):
    print(suffix[i])
