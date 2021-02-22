#include <iostream>

using namespace std;
int N,kg;
int weight[101], value[101];
int dp[101][100001];  

int solve(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= kg; j++){
            if(j - weight[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);        
            else dp[i][j] = dp[i-1][j];
        }

    return dp[N][kg];
}

int main(){
    cin >> N >> kg;
    for(int i = 1; i <= N; i++)
        cin >> weight[i] >> value[i];
    cout << solve();
    return 0;
}