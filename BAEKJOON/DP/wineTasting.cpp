#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n;
int wine[10001];
int cache[10001]; // 합

// 계단 문제랑 동일한데 마지막 잔을 반드시 마셔야 한다는 조건이 없음
// -> 현재 경우에서 마시지 않는 경우를 고려
int tasting(){
    for(int i = 1; i < 3; i++)
        i == 1 ? cache[i] = wine[i] : cache[i] = wine[i] + wine[i-1]; // wine 2잔 이하
    
    int sav = -1;
    for(int i = 3; i <= n; i++){
        sav = max(cache[i-2] + wine[i], cache[i-3] + wine[i-1] + wine[i]);
        sav = max(cache[i-1], sav); // 안마시는게 이득일수 있다
        cache[i] = sav;
    }
    
    return cache[n];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> wine[i];
    memset(cache,0,sizeof(cache));
    cout << tasting() << endl;
    return 0;
}