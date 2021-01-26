#include <iostream>
#include <string>
#include <cstring>

#define BOARD_SIZE 5
#define MAX_WORD_NUM 10
using namespace std;

char board[BOARD_SIZE][BOARD_SIZE]; // 알파벳
string wordList[MAX_WORD_NUM]; // 단어
int dx[8] = {0,1,1,1,0,-1,-1,-1}; // 12시부터 시계방향
int dy[8] = {-1,-1,0,1,1,1,0,-1}; 
bool SearchWordInBoard(int y, int x, const string& word);
void PlayBoggleGame(int idx);
int posY = 0, posX = 0;

bool SearchWordInBoard(int y, int x, const string& word){
    if(y < 0 || x < 0 || y > 4 || x > 4) return false; // 범위 초과
    if(board[y][x] != word[0]) return false; // 글자가 다를경우
    if(word.size() == 1) return true; // 마지막 글자

    for(int i = 0; i < 8; i++){
        posY = y + dy[i];
        posX = x + dx[i];
        if(SearchWordInBoard(posY, posX, word.substr(1))); // idx 1 to word.size() - 1
            return true;
    }
    return false;
}

void PlayBoggleGame(int idx){
    bool flag = false;
    for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            if(board[y][x] == wordList[idx].at(0))
                if(SearchWordInBoard(y,x,wordList[idx])){
                    flag = true;
                    break;
                }
        }
        if(flag) break;
    }
    if(flag) cout << wordList[idx] << " YES" << endl;
    else cout << wordList[idx] << " NO" << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        for(int i = 0; i < BOARD_SIZE; i++)
            for(int j = 0; j <BOARD_SIZE; j++)  
                cin >> board[i][j]; 

        int wordCnt;
        cin >> wordCnt;
        for(int i = 0; i < wordCnt; i++) // 알파벳은 반드시 대문자 1 ~ 10글자
            cin >> wordList[i];

        for(int x = 0 ; x < BOARD_SIZE; x++){
            for(int y = 0; y < BOARD_SIZE; y++){
                    cout << board[x][y] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < wordCnt; i++)
            PlayBoggleGame(i); // i번째 단어 찾기 시작
    }
    return 0;
}