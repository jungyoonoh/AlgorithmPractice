#include <iostream>
#include <string.h>
#include <vector>

#define MOD 1000000007
using namespace std;

vector<vector<long long>> A(2, vector<long long>(2)), res(2, vector<long long>(2));
long long t, i = 0, N, forWard[10000];

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> C(2, vector<long long>(2));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++){
                C[i][j] += a[i][k] * b[k][j];
                C[i][j] %= MOD;
            }
    return C;
}

int main(){
    cin >> N;
    if(N == 0) {cout << "0"; return 0;}
    if(N == 1 || N == 2) {cout << "1"; return 0;}
    while(N > 1){
        forWard[i++] = (N % 2);
        N /= 2;
    }
    A[0][0] = A[0][1] = A[1][0] = 1; A[1][1] = 0;
    for(int k = i - 1; k >= 0; k--){
        if(k == i - 1) res = multiply(A, A);
        else res = multiply(res, res);
        if(forWard[k] == 1)
            res = multiply(res, A);
    }    
    cout << res[1][0] % MOD;

    return 0;
}