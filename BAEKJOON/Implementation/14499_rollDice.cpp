#include <iostream>
#include <string.h>
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

using namespace std;

int N, M, x,y, K, command[1001], map[20][20];
int dice[6] = {0, }; // 0은 항상 윗면
int mv[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

void rollDice(int command){
    int beforeDice[6];
    for(int i = 0; i < 6; i++)
        beforeDice[i] = dice[i];

    if(command == RIGHT){
        // 동
        dice[0] = beforeDice[3];
        dice[3] = beforeDice[5];
        dice[5] = beforeDice[2];
        dice[2] = beforeDice[0];
    }else if(command == LEFT){
        // 서
        dice[0] = beforeDice[2];
        dice[2] = beforeDice[5];
        dice[5] = beforeDice[3];
        dice[3] = beforeDice[0];
    }else if(command == UP){
        // 북
        dice[0] = beforeDice[4];
        dice[4] = beforeDice[5];
        dice[5] = beforeDice[1];
        dice[1] = beforeDice[0];
    }else if(command == DOWN){
        // 남
        dice[0] = beforeDice[1];
        dice[1] = beforeDice[5];
        dice[5] = beforeDice[4];
        dice[4] = beforeDice[0];
    }
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N >> M >> y >> x >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    memset(dice,0,sizeof(dice));
    for(int i = 0; i < K; i++)
        cin >> command[i];
    int dy,dx,idx = 0;
    for(int i = 0; i < K; i++){
        int dir = command[i];
        dy = mv[dir - 1][0];
        dx = mv[dir - 1][1];
        if(y + dy < 0 || y + dy >= N || x + dx < 0 || x + dx >= M) continue;
        rollDice(dir);
        y += dy;
        x += dx;
        if(map[y][x] == 0)
            map[y][x] = dice[5];
        else{
            dice[5] = map[y][x];
            map[y][x] = 0;
        }
        cout << dice[0] << endl;
    }
    return 0;
}