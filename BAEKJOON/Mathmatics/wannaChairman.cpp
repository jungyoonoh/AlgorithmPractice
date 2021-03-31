#include <iostream>

using namespace std;

int apart[15][15]; // 층, 호 1 ~ 14까지 가능

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);

    for(int i=0; i < 15; i++) apart[0][i] = i;    

    for(int i = 1; i <= 14; i++)
        for(int j = 1; j <=14; j++)
            for(int k = 1; k <= j; k++)
                apart[i][j] += apart[i-1][k]; 
                           
    int K,N,T;
    cin >> T;
    while(T--){
        cin >> K >> N;
        cout << apart[K][N] << '\n';
    }
    return 0;
}