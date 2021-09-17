# 1068번 트리 (Tree) 
# https://www.acmicpc.net/problem/1068

N = int(input())
info = list(map(int, input().split()))
K = int(input())
def cut(k):
    info[k] = -2 # 현재 Node 비활성
    # 다음 Node 중에 현재 Node를 부모로 가지고 있는 녀석이 있다면
    for i in range(len(info)): 
        if info[i] == k: 
            cut(i) # 얘도 비활성

cut(K)

cnt = 0
for i in range(len(info)):
    # 부모를 가지고 있고(활성 상태) & i가 info에 없다, 즉 부모로 레퍼런싱 되고 있지 않다면 카운트(Leaf)
    if info[i] != -2 and i not in info:
        cnt += 1

print(cnt)