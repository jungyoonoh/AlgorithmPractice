#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N,savN,A,B,C,cnt = 0;
    cin >> N;
    savN = N;
    do{
        if(N < 10){
            A = 0; B = N; C = A+B;
        } else{
            A = N / 10; B = N % 10; C = A+B; 
        }
        C %= 10;
        N = 10*B+C;
        cnt++;
    }while(savN != N);
    cout << cnt;
    return 0;
}