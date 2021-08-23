#include <iostream>
#include <string>
using namespace std;

// 흰색 0, 검정 1
int N;
string board[65];

bool canSplit(int y1, int x1, int y2, int x2){
    for(int i = x1; i < x2; i++)
        for(int j = y1; j < y2; j++)
            if(board[y1].at(x1) != board[j].at(i)) return true;
    return false;
}

string quadTree(int y1, int x1, int y2, int x2){
    // 숫자 리턴
    if(y1 == y2) return to_string((board[y1].at(x1) - '0'));
    // 숫자 리턴
    if(!canSplit(y1,x1,y2,x2)) return to_string((board[y1].at(x1) - '0'));

    string res = "(";
    int xMid = (x1+x2) / 2;
    int yMid = (y1+y2) / 2;
    string LU = quadTree(y1,x1,yMid,xMid);
    string RU = quadTree(y1,xMid,yMid,x2);
    string LD = quadTree(yMid,x1,y2,xMid);
    string RD = quadTree(yMid,xMid,y2,x2);
    res += LU+RU+LD+RD+")";
    return res;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> board[i];
    cout << quadTree(0,0,N,N);
    return 0;
}