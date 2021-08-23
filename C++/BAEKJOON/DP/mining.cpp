#include <iostream>
#include <string.h>
#include <algorithm>
#define SIZE 301
using namespace std;

int map[SIZE][SIZE], cache[SIZE][SIZE];
int N, M;

int main(){
    cin >> N >> M;
    memset(cache, 0, sizeof(cache));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> map[i][j];
        
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]) + map[i][j];
        
    cout << cache[N][M];
    return 0;
}