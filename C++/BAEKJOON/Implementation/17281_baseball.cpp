#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, res[51][10], lineUp[10], ret = -1;

int play(){
    int score = 0, turn = 1;
    // N 이닝 테스트
    for(int i = 1; i <= N; i++){
        int outCnt = 0, base[5] = {0,}; // 0 : 현재 치는 타자, 1루 ~ 3루, 4 : 홈(점수)
        while(true){
            if(turn == 10) turn = 1;
            if(outCnt == 3) {
                // 다음 이닝
                for(int j = 0; j <= 4; j++) 
                    base[j] = 0;                
                break;
            }
            // 타석에 들어섬
            base[0] = 1;
            // 아웃
            if(res[i][lineUp[turn]] == 0) outCnt++;
            else {
                // 3루부터 이동
                for(int j = 3; j >= 0; j--){
                    if(base[j] == 1){
                        if(j + res[i][lineUp[turn]] >= 4) score++;
                        else base[j + res[i][lineUp[turn]]] = 1;                        
                        base[j] = 0;
                    }                    
                }
            }
            turn++;
        }
    }   
    return score;
}


// 2번선수부터 라인업 정하기
void setLineUp(int num){
    if(num > 9){
        ret = max(ret, play());
        return;
    }    

    for(int i = 1; i <= 9; i++){
        // i번 타자는 cnt번
        if(lineUp[i] == -1){            
            lineUp[i] = num;
            setLineUp(num+1);
            lineUp[i] = -1;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= 9; j++)
            cin >> res[i][j];
    memset(lineUp, -1 , sizeof(lineUp));
    lineUp[4] = 1; // 4번 타자는 1번
    setLineUp(2);
    cout << ret;
    return 0; 
}