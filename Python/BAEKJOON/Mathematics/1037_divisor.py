# 1037번 약수 (Math) 
# https://www.acmicpc.net/problem/1037
# 간단한 수학문제를 손으로 먼저 설계하고 IDE를 돌려보는 연습을 수행합니다 (면접 손코딩 대비)

# 1과 N이 아닌 N의 약수 리스트를 바탕으로 N을 구하려면 약수의 최댓값과 최솟값을 곱한다

N = int(input())
numList = list(map(int, input().split()))
print(max(numList) * min(numList))