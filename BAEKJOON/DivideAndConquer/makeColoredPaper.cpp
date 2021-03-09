#include <iostream>

using namespace std;

int w = 0,b = 0,N, paper[130][130];

// 4µîºÐ
// y1, x1, y2, x2

bool canSplit(int y1, int x1, int y2, int x2){
    for(int i = x1; i < x2; i++)
        for(int j = y1; j < y2; j++)
            if(paper[i][j] != paper[x1][y1]) return true;        
    return false;
}

void splitRect(int y1, int x1, int y2, int x2){
    if(y1 == y2) return;

    if(!canSplit(y1,x1,y2,x2)) {
        paper[x1][y1] == 1 ? b++ : w++;
        return;        
    }

    int yMid = (y1 + y2) / 2;
    int xMid = (x1 + x2) / 2;

    splitRect(y1,x1,yMid,xMid); // ÁÂ»ó
    splitRect(y1,xMid,yMid,x2); // ¿ì»ó
    splitRect(yMid,x1,y2,xMid); // ÁÂÇÏ
    splitRect(yMid,xMid,y2,x2); // ¿ìÇÏ
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    
    splitRect(0,0,N,N);
    cout << w << '\n';
    cout << b << '\n';
    return 0;
}