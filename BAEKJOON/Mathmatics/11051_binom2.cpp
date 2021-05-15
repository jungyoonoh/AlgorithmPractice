#include <iostream>
#include <string.h>

using namespace std;
int N, K;
long long dp[1001][1001];

long long solve(int n, int k){
    if(k == 0 || n == k) return dp[n][k] = 1;
    if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = (solve(n-1, k) % 10007 + solve(n-1, k-1) % 10007) % 10007; 
}

int main(){
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve(N,K);
    return 0;
}