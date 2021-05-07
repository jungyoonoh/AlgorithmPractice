#include <iostream>

using namespace std;

long long N,dp[1001];

int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= N; i++){
        dp[i] = 2 * dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }

    cout << dp[N];
    
    return 0; 
}