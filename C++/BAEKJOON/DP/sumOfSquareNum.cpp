#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N, dp[100001];
    cin >> N;
    for(int i = 1; i <= N; i++)
        dp[i] = i;

    // 처음에 pow(floor(sqrt(N)), 2)를 이용하려 했으나
    // 43의 경우 가장 가까운 제곱수 (36)를 이용하지 않아야 정답인 경우가 있어
    // DP로 재접근
    for(int i = 1; i <= N; i++)
        for(int j = 1; j*j <= i; j++)
            dp[i] = min(dp[i], dp[i - j*j] + 1);

    cout << dp[N];
    return 0;
}