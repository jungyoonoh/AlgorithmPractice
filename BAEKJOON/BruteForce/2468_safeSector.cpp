#include <iostream>
#include <string.h>
#include <algorithm>

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

using namespace std;

int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

int N, map[100][100];
bool isOver[100][100];
bool isVisit[100][100];

int solve(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= N) return 0;
    
    if(isOver[y][x]) return 0;
    if(isVisit[y][x]) return 0;

    isVisit[y][x] = true;

    for(int i = 0; i < 4; i++)
        solve(y + dir[i][0], x + dir[i][1]);
    
    return 1;
}

void checkOver(int height){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!isOver[i][j] && map[i][j] <= height) 
               isOver[i][j] = true; 
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    memset(isOver,0,sizeof(isOver));
    int M = -1;
    for (int height = 0; height <= 100; height++){
        int cnt = 0;
        checkOver(height);
        memset(isVisit,0,sizeof(isVisit));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if(solve(i,j) == 1) cnt++;
            }
        }
        M = max(M, cnt);
    }
    cout << M;
    return 0;
}