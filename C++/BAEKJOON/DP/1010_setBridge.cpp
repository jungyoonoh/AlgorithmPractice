#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

// 동쪽 중에서 N개 뽑기
long long bridge[31][31];
long long N,M,T;

long long solve(int n, int r){
    if(r == 0 || n == r) return bridge[n][r] = 1;
    if(bridge[n][r] != -1) return bridge[n][r];

    return bridge[n][r] = solve(n-1,r-1) + solve(n-1,r);
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> T;
    memset(bridge, -1, sizeof(bridge));
    while(T--){
        cin >> N >> M;
        cout << solve(M,N) << endl;
    }
    return 0;
}