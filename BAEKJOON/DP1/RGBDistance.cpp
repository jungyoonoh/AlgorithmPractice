#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int R[1002], G[1002], B[1002];
int sum[1002][3] = {0,};

// 연속된 색은 칠할 수 없다. 

int draw(int idx){
    if(idx == N) return 0;

    sum[idx][0] = min(sum[idx-1][1], sum[idx-1][2]) + R[idx];
    sum[idx][1] = min(sum[idx-1][0], sum[idx-1][2]) + G[idx];
    sum[idx][2] = min(sum[idx-1][0], sum[idx-1][1]) + B[idx];
    draw(idx + 1);
    int minimum = 987654321;
    for(int i = 0; i < 3; i++)
        if(sum[N-1][i] < minimum) minimum = sum[N-1][i];
    return minimum;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> R[i] >> G[i] >> B[i];

    sum[0][0] = R[0];
    sum[0][1] = G[0];
    sum[0][2] = B[0];
    
    cout << draw(0) << endl;
    return 0;
}