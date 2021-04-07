#include <iostream>
#include <string.h>
#include <algorithm>
#define DAY_1 10000
#define DAY_3 25000
#define DAY_5 37000
#define MAX 2147483647

using namespace std;

int N,M,day,coupon = 0;
int canGo[101], price[101], dp[101][101];

int solve(int day, int coupon){
    if(day > N) return 0;
    // dp[day][coupon] 그 날로부터 이후 날까지 가는 금액의 최솟값
    if(dp[day][coupon] != MAX) return dp[day][coupon];

    if(canGo[day] == -1)
        return dp[day][coupon] = solve(day + 1, coupon); // skip
    else {
        if(coupon >= 3)
            dp[day][coupon] = min(dp[day][coupon], solve(day + 1, coupon - 3));
        dp[day][coupon] = min({dp[day][coupon], DAY_1 + solve(day + 1, coupon)});
        dp[day][coupon] = min(dp[day][coupon], DAY_3 + solve(day + 3, coupon + 1));
        dp[day][coupon] = min(dp[day][coupon], DAY_5 + solve(day + 5, coupon + 2));
    }    
    return dp[day][coupon];    
}

void init(){
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            dp[i][j] = MAX;
    memset(canGo, 0, sizeof(canGo));
}

int main(){
    cin >> N >> M;
    init();
    for(int i=1; i<=M; i++){
        cin >> day;
        canGo[day] = -1;
    }
    cout << solve(1,0);    
    return 0;
}