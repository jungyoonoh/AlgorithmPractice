#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1001];
int dp[1001]; // 정방향
int rdp[1001]; // 역방향

int solve(){
    for(int i = 1; i <= N; i++){
        int pos = 0, rpos = 0;
        for(int j = 1; j < i; j++){
            if(A[j] < A[i])
                pos = max(pos, dp[j]);
            if(A[N - j + 1] < A[N - i + 1])
                rpos = max(rpos, rdp[j]);
        }
        dp[i] = pos + 1; 
        rdp[i] = rpos + 1; // dp는 순차
    }
    int sum = -1;

    for(int i = 1; i <= N; i++)
        sum = max(sum, dp[i] + rdp[N - i + 1]);
    return sum - 1;
}

int main(){
    cin >> N;
    for(int i = 1; i <= N ; i++)
        cin >> A[i];
    
    cout << solve() << endl;
    return 0;
}