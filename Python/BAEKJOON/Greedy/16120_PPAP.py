# 16120번 PPAP (Greedy) 
# https://www.acmicpc.net/problem/16120

PPAP = list(input())
st = []

for i in PPAP:
    if len(st) < 4:
        st.append(i)
        continue
    
    if ''.join(st[-4:]) == 'PPAP':
        for _ in range(3):
            st.pop()
    
    st.append(i)

ans = ''.join(st)
print('PPAP' if ans == 'PPAP' or ans == 'P' else 'NP')