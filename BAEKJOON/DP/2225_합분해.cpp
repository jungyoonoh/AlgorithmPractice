#include <iostream>

using namespace std;

int N, K, C = 0;


void solve(int idx, int cnt, int sum){
    if(cnt == K){
        if(sum == N){ C++; C %= 1000000000; return; }
        else return;
    }
    for(int i = idx; i <= N; i++)
        solve(i, cnt + 1, sum + i);
}


int main(){
    cin >> N >> K;
    solve(0,0,0);    
    cout << C;
}