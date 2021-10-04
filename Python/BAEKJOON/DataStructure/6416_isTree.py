# 6416번 트리인가? (Tree) 
# https://www.acmicpc.net/problem/6416

import sys

input = sys.stdin.readline
tcEnd = False
i = 1
while not tcEnd: # TC
    caseEnd = False
    isTree = True
    isDirect = set()
    isDirected = set()
    while not caseEnd:
        temp = list(map(int, input().rstrip().split()))
        for _ in range(0, len(temp) // 2):
            if temp[0] == 0 and temp[1] == 0:
                caseEnd = True
                break
            if temp[0] == -1 and temp[1] == -1:
                caseEnd = True
                tcEnd = True
                break
            isDirect.add(temp[0])
            if temp[1] not in isDirected:
                isDirected.add(temp[1])
            else:
                isTree = False
                break
            del temp[0]
            del temp[0]

    if isTree:
        diffset = isDirect - isDirected
        if len(diffset) != 1:
            isTree = False
        if len(isDirect) == 0 and len(isDirected) == 0:
            isTree = True

    if tcEnd: break
    
    if isTree: print("Case "+str(i)+" is a tree.")
    else: print("Case "+str(i)+" is not a tree.")
    
    i += 1