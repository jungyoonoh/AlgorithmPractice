#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, range = 0, fmax = -1, rmax = -1, M;
int wire[501]; // [a] = b  -> a,b ����
int dp[501];

int solve(){
    for(int i = 1; i <= range; i++){
        int maxPos = 0;
        for(int j = 1; j < i; j++)
            if((wire[j] != -1) && (wire[i] != -1) && (wire[j] < wire[i])) maxPos = max(maxPos, fdp[j]);
        dp[i] = maxPos + 1;
    }
    for(int i = 1; i <= range; i++)
        fmax = max(fmax, dp[i]);
    M = max(M, fmax);
    return N - M;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b;
    memset(wire,-1,sizeof(wire));
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        wire[a] = b;
        range = max(range, max(a,b));
    }
    cout << solve();
    return 0;
}