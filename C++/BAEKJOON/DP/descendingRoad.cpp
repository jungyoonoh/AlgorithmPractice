#include <iostream>
#include <string.h>
#define SIZE 500
using namespace std;

int M, N, cnt = 0, map[SIZE][SIZE], cache[SIZE][SIZE]; // y,x
int moveDir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 오 아 왼 위, y, x
// 상하좌우 모두 가능함 

// 수학 길찾기 거꾸로 버전
// y,x 좌표로, 현재 값보다. 비교
// map[a][b] 를 가는 경로의 수의 합 + 몇개 
bool canMove(int y, int x, int value){
    if(y < 0 || y >= M || x < 0 || x >= N) return false;
    if(map[y][x] < value) return true;
    return false;
}

int find(int y, int x){
    if(y == M - 1 && x == N - 1) return 1;

    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i < 4; i++)
        if(canMove(y + moveDir[i][0], x + moveDir[i][1], map[y][x]))
            ret += find(y + moveDir[i][0], x + moveDir[i][1]);
    
    return ret;
}


int main(){
    cin >> M >> N;
    memset(cache,-1, sizeof(cache));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    cout << find(0,0);
    return 0; 
}