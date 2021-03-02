#include <iostream>
#include <string>

using namespace std;

string board[51];

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int N, M, m = 987654321;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++)
        cin >> board[i];

    // 좌상단 기준으로 기준에 맞지 않는 블럭이 몇개인지 카운트
    for(int i = 0; i < N - 7; i++){
        for(int j = 0; j < M - 7; j++){
            int cntW = 0, cntB = 0,color = (i + j % 2);
            for(int k = i; k < i+8; k++){
                for(int l = j; l < j+8; l++){
                    if((k + l) % 2 == 0) board[k][l] == 'B' ? cntW++ : cntB++;
                    else board[k][l] == 'B' ? cntB++ : cntW++;                    
                }
            }
            m = min(m,cntW);
            m = min(m,cntB);
        }
    }
    cout << m;
   
    return 0;
}