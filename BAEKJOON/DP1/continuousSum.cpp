#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int n;
int S[100001];
int dp[100001]; // dp[i] i를 포함하는 연속합 중 최댓값

// 시간 초과
// int solve(){
//     dp[0] = 0;
//     for(int i = 1; i <= n; i++)
//         dp[i] = dp[i - 1] + S[i];
//     for(int i = 2; i <= n; i++){
//         int m = -987654321;
//         int temp = dp[i];
//         for(int j = 1; j < i; j++){
//             temp -= S[j];
//             m = max(m, max(dp[i], temp));
//         }
//         dp[i] = m;
//     }
//     int ret = -987654321;
//     for(int i = 1; i <= n; i++)
//         ret = max(ret, dp[i]);
//     return ret;
// }

int solve(){
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        dp[i] = max(dp[i - 1] + S[i], S[i]);

    int ret = dp[1];
    for(int i = 2; i <= n; i++)
        ret = max(ret, dp[i]);
    return ret;
}

int main(){
    cin >> n;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
        cin >> S[i];
    cout << solve();
    return 0;
}