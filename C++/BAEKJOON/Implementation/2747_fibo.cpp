#include <iostream>
#include <string.h>

using namespace std;
int N;
long long dp[46];
long long solve(int N){
    if(N == 0) return 0;
    if(N == 1) return 1;
    if(dp[N] != -1) return dp[N];
    dp[N] = solve(N-1) + solve(N-2);
    return dp[N];
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << solve(N);
    return 0;
}