import itertools
from collections import defaultdict
def solution(orders, course):
    answer = []
    
    for num in course:
        orderCnt = defaultdict(int)
        orderList = []
        for order in orders:
            orderList.extend(list(itertools.combinations(sorted(order), num)))

        for element in orderList:
            s = ''.join(element)
            orderCnt[s] += 1
        
        if len(orderCnt) > 0:
            M = max(list(orderCnt.values()))
            for s in orderCnt.keys():
                if orderCnt[s] == M and orderCnt[s] > 1:
                    answer.append(s)
    answer.sort()
    return answer

print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]))
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2,3,5]))
print(solution(["XYZ", "XWY", "WXA"], [2,3,4]))