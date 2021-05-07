#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, dp[16];
pair<int, int> d[16];

int doIt(int day){
    if(day == N+1) return 0; // 쭉 스킵해서 N일 지났을 경우
    if(day > N+1) return -2147483647; // 특정 상담 골랐는데 초과일 경우
    int& res = dp[day];
    if(res != -1) return res;
    res = 0;
    res += max(d[day].second + doIt(day + d[day].first), doIt(day+1));
    return res;
}

int main(){
    cin >> N;
    int T, P;
    for(int i = 1; i <= N; i++)
        cin >> d[i].first >> d[i].second;
    memset(dp, -1, sizeof(dp));
    cout << doIt(1);
    return 0;
}