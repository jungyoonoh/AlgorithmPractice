# 14916번 거스름돈 (Greedy) 
# https://www.acmicpc.net/problem/14916
# 기본 거스름돈은 단위가 배수관계, 이 문제는 배수관계가 아닌 경우

N = int(input())

if N % 5 == 0:
    print(N // 5)
elif N == 1 or N == 3:
    print(-1)
elif N % 5 == 2 or N % 5 == 4:
    print(N // 5 + ((N % 5) // 2))
elif N % 5 == 1 or N % 5 == 3:
    print((N - 5) // 5 + (((N - 5) % 5) + 5) // 2)
