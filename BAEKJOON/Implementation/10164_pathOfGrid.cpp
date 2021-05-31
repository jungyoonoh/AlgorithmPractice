#include <iostream>
#include <string.h>

using namespace std;
int N,M,K;
long long dp[16][16];
int main(){
    cin >> N >> M >> K;
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    int y = 1, x = 1;
    bool flag = false;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if((i-1) * M + j == K){
                y = i;
                x = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(K != 0){
        for(int i = 1; i <= y; i++)
            for(int j = 1; j <= x; j++){
                if(i == 1 && j == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];        
            }

        for(int i = y; i <= N; i++)
            for(int j = x; j <= M; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];            
    }else {
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++){
                if(i == 1 && j == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
    }
    cout << dp[N][M];

    return 0;
}