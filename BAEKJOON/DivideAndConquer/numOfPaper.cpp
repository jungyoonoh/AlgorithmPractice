#include <iostream>

using namespace std;

int cnt[3] = {0, }, N, board[2190][2190];

bool checkCut(int y1, int x1, int y2, int x2){
    for(int i = x1; i < x2; i++)
        for(int j = y1; j < y2; j++)
            if(board[y1][x1] != board[j][i]) return true;
    return false;
}

void cutPaper(int y1, int x1, int y2, int x2){
    if(!checkCut(y1,x1,y2,x2)) { cnt[board[y1][x1] + 1]++; return; }

    int t = (x2-x1) / 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cutPaper(y1+t*i, x1+t*j, y1+t*(i+1), x1+t*(j+1));
    return;    
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    cutPaper(0,0,N,N);
    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';
    return 0;
}