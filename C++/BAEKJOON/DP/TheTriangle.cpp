#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int tri[501][501]; // 삼각형 내부 요소의 값
int sum[501][501]; // 지점에 도달 합

int solve(int depth, int idx){
    if(depth == n) return 0;

    int& ret = sum[depth][idx];
    if(ret != -1) return ret;

    ret = tri[depth][idx] + max(solve(depth + 1, idx), solve(depth + 1, idx + 1));

    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> tri[i][j];
    memset(sum,-1,sizeof(sum));
    cout << solve(0,0) << endl;    
    return 0;
}