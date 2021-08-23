price = int(input())
N = 1000 - price 
count = 0

coin_type = [500,100,50,10,5,1]

for coin in coin_type:
    count += N // coin
    N %= coin

print(count)
