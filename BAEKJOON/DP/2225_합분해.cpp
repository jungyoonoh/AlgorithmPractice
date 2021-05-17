#include <iostream>
#include <string.h>
#define MOD 1000000000
using namespace std;

long long N, K, dp[201][201];

long long solve(int n, int k){
    if(n == 0 || k == 1) return dp[n][k] = 1;
    if(dp[n][k] != 0) return dp[n][k];

    for(int i = 0; i <= n; i++)
        dp[n][k] += solve(i, k-1) % MOD;
    return dp[n][k] % MOD;
}


int main(){
    cin >> N >> K;
    memset(dp,0,sizeof(dp));
    cout << solve(N,K);
}