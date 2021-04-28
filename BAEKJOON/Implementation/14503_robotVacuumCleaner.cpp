#include <iostream>
#include <string.h>
#include <queue>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define SIZE 51

using namespace std;

int N,M,r,c,d;
int map[SIZE][SIZE];
int isClean[SIZE][SIZE];
queue<pair<pair<int,int>, int>> q;

// 왼쪽부터 탐색 진행
// 1. 현재 위치를 청소한다.
// 2. 왼쪽에 청소 안됐을 경우 왼쪽으로 회전 후 한칸 전진 후 1번부터 다시
// 3. 왼쪽 방향에 청소할 공간이 없다면 그 방향으로 회전하고 2번으로 돌아간다.
// 4. 네 방향 모두 청소가 되어있거나 벽인 경우에는 바라보는 방향 유지한 채 후진하고 2번
// 5. 네 방향 모두 청소가 되어있거나 벽이면서 뒤쪽 방향이 벽이라 후진할 수 없는 경우에 작동 멈춤

// 이미 청소된곳은 청소안함, 벽은 통과 못함.

int count(){
    int ret = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(isClean[i][j] == 1) ret++;
    return ret;
}

void solve(){
    int dy,dx;
    while(!q.empty()){ // 움직이지 못하는 조건 해결을 위함
        bool flag = false;
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        // 제자리 청소
        if(isClean[y][x] == 0) 
            isClean[y][x] = 1;
        q.pop();

        // 회전
        for(int i = 0; i < 4; i++){ 
            int moveDir = (dir + 3 - i) % 4; // 회전
            switch(moveDir){
            // 현재 방향 대비 왼쪽으로 다음 이동방향 결정해야함
                case UP: dy = -1; dx = 0; break;
                case RIGHT: dy = 0; dx = 1; break;
                case DOWN: dy = 1; dx = 0; break;
                case LEFT : dy = 0; dx = -1; break;
            }

            int moveY = y + dy;
            int moveX = x + dx;
            
            if(moveY >= 0 && moveY < N && moveX >= 0 && moveX < N){
                // 청소 안됐을때만 이동
                if(isClean[moveY][moveX] == 0 && map[moveY][moveX] == 0){
                    q.push({{moveY, moveX}, moveDir});
                    flag = true;
                    break;
                }
            }            
        }        

        // 네 방향 청소 확인
        if(!flag) {            
            switch(dir){                       
                case UP: dy = -1; dx = 0; break;
                case RIGHT: dy = 0; dx = 1; break;
                case DOWN: dy = 1; dx = 0; break;
                case LEFT : dy = 0; dx = -1; break;
            }

            int moveY = y - dy; // 반대 방향 이동
            int moveX = x - dx;
            
            if(moveY >= 0 && moveY < N && moveX >= 0 && moveX < N){
                // 뒤가 벽이면
                if(map[moveY][moveX] == 1){
                    break;
                }else{                    
                    // 몸은 그대로 기계만 후진
                    q.push({{moveY, moveX}, dir});
                }
            }     
        }
    }
}

int main(){
    cin >> N >> M; 
    cin >> r >> c >> d;
    q.push({{r,c}, d});
    memset(isClean, 0, sizeof(isClean));
    memset(map,-1,sizeof(map));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    solve();
    
    cout << count();

    return 0;
}