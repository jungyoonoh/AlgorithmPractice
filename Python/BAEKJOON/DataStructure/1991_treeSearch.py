# 1991번 트리순회 (Tree) 
# https://www.acmicpc.net/problem/1991

N = int(input())
tree = dict()
for i in range(N):
    root, left, right = input().split()
    tree[root] = [left, right]
    
# pre
def preOrder(idx):
    if idx == '.': return
    print(idx, end='')
    preOrder(tree[idx][0])
    preOrder(tree[idx][1])

# in
def inOrder(idx):
    if idx == '.': return
    inOrder(tree[idx][0])
    print(idx, end='')
    inOrder(tree[idx][1])

# post 
def postOrder(idx):
    if idx == '.': return
    postOrder(tree[idx][0])
    postOrder(tree[idx][1])
    print(idx, end='')
    
preOrder('A')
print()
inOrder('A')
print()
postOrder('A')