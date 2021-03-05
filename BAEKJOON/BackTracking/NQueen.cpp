#include <iostream>
#include <string.h>
using namespace std;

// 0이면 둘 수 있음, 1이면 둘 수 없음
int ans = 0, N, chess[15][15];

// 위쪽 볼필요x, 행정보는 반드시 한줄 이동하므로 x
// -> 퀸을 놓은 칸 기준으로 아래쪽 영역만 확인
void putIt(int y, int x, int value){
    for(int i = 1; y+i < N; i++){
        chess[y+i][x] += value;
        if(x - i >= 0) chess[y+i][x-i] += value;
        if(x + i < N) chess[y+i][x+i] += value;
    }
}

// 다음줄로 이동
void doIt(int y){
    if(y == N) {
        ans++;
        return;
    }
    for(int x = 0; x < N; x++){
        if(chess[y][x] == -1){
            putIt(y,x,1);
            doIt(y+1);
            putIt(y,x,-1);
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N;
    memset(chess,-1,sizeof(chess));
    doIt(0);
    cout << ans;
    return 0;
}