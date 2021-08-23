#include <iostream>
#include <string.h>
#include <algorithm>
#define SIZE 100002
using namespace std;
int T, N;
int table[2][SIZE], cache[2][SIZE];

// select or skip 가능 
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < N; j++)
                cin >> table[i][j];
        memset(cache, 0, sizeof(cache));
        for(int i = 2; i <= N+1; i++){
            cache[0][i] = max(cache[1][i-1], cache[1][i-2]) + table[0][i - 2];
            cache[1][i] = max(cache[0][i-1], cache[0][i-2]) + table[1][i - 2];
        }
        cout << max(cache[0][N+1], cache[1][N+1]) << '\n';
    }
    return 0;
}