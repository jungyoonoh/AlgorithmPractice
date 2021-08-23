#include <iostream>
#include <string.h>
using namespace std;

int A[100][100], B[100][100], C[100][100], N, M, K;

void multiply(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < K; j++)
            for(int k = 0; k < M; k++)
                C[i][j] += A[i][k] * B[k][j];
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    memset(C,0,sizeof(C));
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> A[i][j];

    cin >> M >> K;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            cin >> B[i][j];

    multiply();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++)
            cout << C[i][j] << " ";
        cout << '\n';
    }

    return 0;
}