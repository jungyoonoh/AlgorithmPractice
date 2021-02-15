#include <iostream>
#include <algorithm>

using namespace std;

int stairsNum, sav = 0;
int stairs[301];
int cache[301] = {0, }; // -> 도합

// 1. 한번에 1개 or 2개 계단
// 2. 연속된 3개의 계단 X
// 3. 마지막은 반드시 밟아야
// 밟지 않는 경우를 캐시로 포함할 이유가 없으므로 현재를 밟는 경우만 갱신
int ascend(){
    for(int i = 0; i < 3; i++) // 계단이 1개 ~ 3개라면
        i == 0 ? cache[i] = stairs[i] : i == 1 ? cache[i] = stairs[i] + stairs[i-1] : cache[i] = max(stairs[i] + stairs[i-1], stairs[i] + stairs[i-2]);
    
    for(int i = 3; i < stairsNum; i++) // 계단이 4개 이상이라면 
        cache[i] = max(cache[i-2] + stairs[i], cache[i-3] + stairs[i-1] + stairs[i]); 
        
    return cache[stairsNum - 1];
}

int main(){
    cin >> stairsNum;
    for(int i = 0; i < stairsNum; i++) 
        cin >> stairs[i];
    cout << ascend() << endl;
    return 0;
}