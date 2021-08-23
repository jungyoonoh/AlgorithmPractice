#include <iostream>
#include <string.h>

using namespace std;

long long N, map[101][101], dp[101][101];

long long solve(int y, int x){
    if(y == N && x == N)
        return dp[y][x] = 1;
    if(dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    if(y + map[y][x] <= N)
        dp[y][x] += solve(y + map[y][x], x);
    if(x + map[y][x] <= N)
        dp[y][x] += solve(y, x + map[y][x]);

    return dp[y][x];
}

int main(){
    cin >> N;
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> map[i][j];        
    cout << solve(1,1);
    return 0;
}