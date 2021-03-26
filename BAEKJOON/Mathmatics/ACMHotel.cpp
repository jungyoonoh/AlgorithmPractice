#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int T,W,N,H;
    cin >> T;
    while(T--){
        cin >> H >> W >> N;
        if(N % H == 0) N / H < 10 ? cout << H << "0" << N/H << '\n': cout << H << N/H << '\n';
        else N / H < 9 ? cout << N % H << "0" << N/H + 1 << '\n' : cout << N % H << N/H + 1 << '\n';
    }
    return 0; 
}