#include <iostream>
#include <string.h>
using namespace std;

// -50 <= a,b,c <= 50
// 전 범위를 캐싱할 필요가 없음
long long cache[21][21][21];
long long solve(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
        
    if(a > 20 || b > 20 || c > 20)
        return solve(20,20,20);

    long long& ret = cache[a][b][c];
    if(ret != -1)
        return ret;

    if(a < b && b < c)
        return ret = solve(a,b,c-1) + solve(a,b-1,c-1) - solve(a,b-1,c);

    return ret = solve(a-1,b,c) + solve(a-1,b-1,c) + solve(a-1,b,c-1) - solve(a-1,b-1,c-1);
}


int main(){
    int a,b,c;
    while(true){
        memset(cache,-1,sizeof(cache));
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a,b,c) << "\n";
    }
    return 0;
}