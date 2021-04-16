#include <iostream>

using namespace std;

int N,K,binary[15][15] = {0, };

int solve(int N, int K){
    if(N == K || K == 0) return 1;
    if(binary[N][K] != 0) return binary[N][K];
    return binary[N][K] = solve(N-1, K) + solve(N-1, K-1);
}

int main(){
    cin >> N >> K;
    cout << solve(N,K);
    return 0;
}