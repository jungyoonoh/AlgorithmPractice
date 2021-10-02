# 프로그래머스 코딩테스트 연습 > 2018 KAKAO BLIND RECRUITMENT > 캐시
# https://programmers.co.kr/learn/courses/30/lessons/17680

def solution(cacheSize, cities):
    answer = 0
    cache = []
    
    if cacheSize == 0:
        answer = len(cities) * 5
        return answer
    
    for city in cities:
        if city.lower() in cache:
            answer += 1
            del cache[cache.index(city.lower())]
            cache.append(city.lower())
        else:
            answer += 5
            if len(cache) >= cacheSize:
                del cache[0]
            cache.append(city.lower())
    
    return answer