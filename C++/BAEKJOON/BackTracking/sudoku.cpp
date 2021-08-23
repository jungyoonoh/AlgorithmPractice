#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 9
using namespace std;

int sudoku[9][9], emptyNum = 0, findNum = 0;
vector<pair<int,int>> emptyList; // y, x
bool flag = false;

void printSudoku(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << " ";
        cout << '\n';
    }
}

bool canPutCheck(int y, int x, int value){
    // row
    for(int i = 0; i < SIZE; i++)
        if(sudoku[y][i] == value) return false;

    // col
    for(int i = 0; i < SIZE; i++)
        if(sudoku[i][x] == value) return false;
    
    // in square
    int yRange = y / 3; // 0 ~ 2
    int xRange = x / 3; // 0 ~ 2
    for(int i = yRange * 3; i < (yRange+1) * 3; i++)
        for(int j = xRange * 3; j < (xRange+1) * 3; j++)
            if(sudoku[i][j] == value) return false;

    return true;
}

void backTracking(int y, int x){
    if(flag) return;
    if(findNum == emptyNum) {printSudoku(); flag = true; return;}
    for(int i = 1; i <= SIZE; i++){
        if(canPutCheck(y,x,i)){
            sudoku[y][x] += i;
            findNum++;
            backTracking(emptyList[findNum].first,emptyList[findNum].second);
            sudoku[y][x] -= i;
            findNum--;
        }
    }
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) emptyList.push_back(pair<int,int>(i,j));
        }

    emptyNum = emptyList.size(); // 찾아야 할 개수
    backTracking(emptyList[0].first, emptyList[0].second);
    return 0;
}