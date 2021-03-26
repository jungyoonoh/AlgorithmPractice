#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N, dp[100001];
    cin >> N;
    for(int i = 1; i <= N; i++)
        dp[i] = i;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j*j <= i; j++)
            dp[i] = min(dp[i], dp[i - j*j] + 1);

    cout << dp[N];

    return 0;
}