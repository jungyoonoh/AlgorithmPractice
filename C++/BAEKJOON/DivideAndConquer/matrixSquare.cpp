#include <iostream>
#include <string.h>
#include <vector>

#define MOD 1000
using namespace std;

vector<vector<int>> A(5, vector<int>(5)), res(5, vector<int>(5));
long long t, i = 0, B, N, forWard[1000];

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> C(5, vector<int>(5));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++){
                C[i][j] += a[i][k] * b[k][j];
                C[i][j] %= MOD;
            }
    return C;
}

void print(vector<vector<int>> r){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << r[i][j] % MOD << " ";
        cout << '\n';
    }
}

int main(){
    cin >> N >> B;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> t;
            A[i][j] = t;
        }
    while(B > 1){
        forWard[i++] = (B % 2);
        B /= 2;
    }
    if(i == 0) {print(A); return 0;}
    for(int k = i - 1; k >= 0; k--){
        if(k == i - 1) res = multiply(A, A);
        else res = multiply(res, res);
        if(forWard[k] == 1)
            res = multiply(res, A);
    }
    print(res);

    return 0;
}