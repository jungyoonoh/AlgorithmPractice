#include <iostream>

using namespace std;

int xy[3][2];
int ans[2];
void solve(){

    // 새로운 고찰
    // ans[0] = xy[0][0] ^ xy[1][0] ^ xy[2][0]; 
    // ans[1] = xy[0][1] ^ xy[1][1] ^ xy[2][1]; 
    // -> x값이 같은 두 녀석의 XOR 비트연산은 0을 만든다
    // 교환법칙이 성립하기에 3개중 2개의 값만 같으면 1개의 값이 그대로 남음

    // 답
    if(xy[0][0] == xy[1][0])
        ans[0] = xy[2][0];
    else if(xy[0][0] == xy[2][0])
        ans[0] = xy[1][0];
    else if(xy[1][0] == xy[2][0])
        ans[0] = xy[0][0];

    if(xy[0][1] == xy[1][1])
        ans[1] = xy[2][1];
    else if(xy[0][1] == xy[2][1])
        ans[1] = xy[1][1];
    else if(xy[1][1] == xy[2][1])
        ans[1] = xy[0][1];

    cout << ans[0] << " " << ans[1] << endl;   
}

int init(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            xy[i][j] = 0;
    ans[0] = ans[1] = 0;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 2; j++)
                cin >> xy[i][j];

        solve();
    }
    return 0;
}