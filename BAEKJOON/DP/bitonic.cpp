#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A[1001], dp[1001], rdp[1001]; // 정방향, 역방향

// 제공하는 예시가 바이토닉이 X
// 수열 S에서 Sk를 기준으로 바이토닉을 만족 && 가장 긴 k 찾기
int solve(){
    for(int i = 1; i <= N; i++){
        int maxPos = 0, maxRpos = 0;
        for(int j = 1; j < i; j++){
            if(A[j] < A[i]) maxPos = max(maxPos, dp[j]);
            if(A[N - j + 1] < A[N - i + 1]) maxRpos = max(maxRpos, rdp[j]);
        }
        dp[i] = maxPos + 1; 
        rdp[i] = maxRpos + 1; // dp는 순차
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