#include <iostream>
#include <string.h>
using namespace std;
int N;  

long long dp[31][31];

long long solve(int one, int half){
    if(one == 0) return 1;
    long long &ret = dp[one][half];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(one - 1, half + 1);

    if(half > 0) ret += solve(one, half - 1);
    return ret;
}

int main(){
    cin.tie(NULL), cin.sync_with_stdio(false);
    while(1){
        cin >> N;
        memset(dp, -1, sizeof(dp));
        if(N == 0) break;
        cout << solve(N,0) << endl;
    }
    return 0;
}