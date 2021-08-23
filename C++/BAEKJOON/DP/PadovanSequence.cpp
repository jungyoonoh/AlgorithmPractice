#include <iostream>
#include <string.h>

using namespace std;

// fibo 스타일은 long long -> 100까지만 가도 64bit over
long long cache[101];
long long P(int n){
    if(n == 1 || n == 2 || n == 3)
        return cache[n] = 1;
    if(n == 4 || n == 5)
        return cache[n] = 2;
    long long& ret = cache[n];
    if(ret != -1)
        return ret;
    return ret = P(n-2) + P(n-3);
}


int main(){
    int TC,n;
    cin >> TC;
    while(TC--){
        memset(cache,-1,sizeof(cache));
        cin >> n;
        cout << P(n) << endl;
    }
    return 0;
}