#include <iostream>

using namespace std;

int N, S, seq[21], cnt = 0;

// 부분 수열이라함은 '연속될 필요가 없음'

void solve(int start, int sum){
    if(sum == S) cnt++;
    for(int i = start + 1; i<=N; i++)
        solve(i, sum + seq[i]);    
}

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++)
        cin >> seq[i];
   
    for(int i = 1; i <= N; i++)
        solve(i, seq[i]);
    
    cout << cnt;

    return 0;
}