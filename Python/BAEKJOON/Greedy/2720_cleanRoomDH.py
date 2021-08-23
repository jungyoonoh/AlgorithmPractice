# 2720번 세탁소 사장 동혁 (Greedy) 
# https://www.acmicpc.net/problem/2720

coin_list = [25,10,5,1]
for _ in range(int(input())):
    refund = int(input())
    ans = list()
    for coin in coin_list:
        ans.append(refund // coin)
        refund %= coin
    print(*ans)