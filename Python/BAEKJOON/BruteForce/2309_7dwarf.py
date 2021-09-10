# 2309번 일곱 난쟁이 (BruteForce) 
# https://www.acmicpc.net/problem/2309

checked = [False] * 9
dwarf = []
ans = []
flag = False

for i in range(9):
    dwarf.append(int(input()))
dwarf = sorted(dwarf)

def solutions(cnt):
    global flag
    if flag: return
    if cnt == 7 and sum(ans) == 100:
        ans.sort()
        for d in ans:
            print(d)
        flag = True
        return

    for i in range(len(dwarf)):
        if not checked[i]:
            checked[i] = True
            ans.append(dwarf[i])
            solutions(cnt + 1)
            ans.pop()
            checked[i] = False

solutions(0)
