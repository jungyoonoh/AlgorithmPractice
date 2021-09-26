# 프로그래머스 코딩테스트 연습 > 스택큐 > 다리를 지나는 트럭
# https://programmers.co.kr/learn/courses/30/lessons/42583

from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = deque()
    for _ in range(bridge_length):
        bridge.append(0)
    i = 0
    M = len(truck_weights)
    bridgeSum = 0
    while True :     
        if i == len(truck_weights) and bridgeSum == 0:
            break

        if bridge[0] != 0:
            bridgeSum -= bridge[0]
        bridge.popleft() 

        nextTruck = 0
        if i != M:
            if bridgeSum + truck_weights[i] <= weight:
                nextTruck = truck_weights[i]
                bridgeSum += truck_weights[i]
                i += 1
      
        bridge.append(nextTruck) 

        answer += 1

    return answer

print(solution(2, 10, [7,4,5,6]))