#include <iostream>
#include <deque>
#include <string.h>
#include <algorithm>

#define APPLE 1
#define BOARD 0

using namespace std;

int N, K, L,a,b, t;
char alpha;
int board[101][101] = {0,};
deque<pair<int,int>> snake;
pair<int, char> direction[100];

// right : 0, up : 1, left : 2, down : 3
int dir[4][2] = {{0,1}, {-1, 0}, {0,-1}, {1,0}};

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N >> K;
    memset(board,0,sizeof(board));
    for(int i = 1; i <= K; i++){
        cin >> a >> b;
        board[a][b] = APPLE;
    }
    cin >> L;
    bool flag = false;
    int time = 0, x = 1, y = 1, dx = 1, dy = 0, dirNum = 0,idx = 0;
    snake.push_back({y,x});
    for(int i = 0; i < L; i++){
        cin >> t >> alpha;
        direction[i].first = t;
        direction[i].second = alpha;
    }
    while(!flag){
        t = direction[idx].first;
        alpha = direction[idx].second;
        while(!flag){
            x += dx;
            y += dy;
            for(int i = 0; i < snake.size(); i++)
                if(snake.at(i).first == y && snake.at(i).second == x) flag = true;
            if(x <= 0 || x > N || y <= 0 || y > N) flag = true;
            snake.push_back({y,x});
            if(board[y][x] != APPLE) snake.pop_front();                
            else board[y][x] = BOARD;
            time++;
            if(flag) break;
            if(time == t) break;
        }
        dirNum = alpha == 'L' ? (dirNum + 1) % 4 : (dirNum + 3) % 4;
        dy = dir[dirNum][0];
        dx = dir[dirNum][1];
        idx++;   
    }
    cout << time;
    return 0;
}