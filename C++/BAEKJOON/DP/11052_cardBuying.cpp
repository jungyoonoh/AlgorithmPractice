#include <iostream>
#include <algorithm>
#include <string.h>
#define SIZE 10001
using namespace std;

int card[SIZE], N, dp[SIZE];

int main(){
    cin >> N;
    memset(dp,-1,sizeof(dp));    
    for(int i = 1; i <= N; i++)
        cin >> card[i];

    dp[1] = card[1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i / 2; j++){
            int temp = max(card[i], dp[i - j] + dp[j]);
            dp[i] = max(dp[i], temp);            
        }        
    }
    cout << dp[N];
    return 0;
}