#include <iostream>
#include <string.h>

using namespace std;
int N, num[10], M = 1;
int main(){
    cin >> N;
    memset(num, 0, sizeof(num));
    while(N > 0){
        num[N % 10]++;
        N /= 10;
    }
    for(int i = 0; i < 10; i++)
        if(i != 6 && i != 9) M = max(M, num[i]);
    int cnt = (num[6] + num[9] + 1) / 2;
    M = max(M, cnt);
    cout << M;
    return 0;
}