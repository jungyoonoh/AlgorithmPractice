#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;
int map[50][50];
int N,M;
int cache[50][50];
string str[50];

queue<pair<int,int>> q;

// 북 동 남 서
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solve(int y, int x){
    memset(cache, 0, sizeof(cache));
    q.push({y,x});
    cache[y][x] = 1; // 시작점 
    int res = 0;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = y + mv[i][0];
            int nextX = x + mv[i][1];

            if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M){
                if(map[nextY][nextX] == 1 && cache[nextY][nextX] == 0){
                    q.push({nextY, nextX});
                    cache[nextY][nextX] = cache[y][x] + 1; // 한칸 이동
                }
            }
            res = max(res, cache[y][x]);
        }
    }
    return res - 1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> str[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(str[i].at(j) == 'W') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }

    int sol = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1){
                sol = max(sol, solve(i,j));
            }
        }
    }
    cout << sol;

    return 0;
}