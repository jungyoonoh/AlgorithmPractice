#include <iostream>

using namespace std;

long long A, B;
int main(){
    int cnt = 1;
    cin >> A >> B;
    while(1){
        if(B % 10 == 1) B /= 10;
        else if(B % 2 == 1) {cout << -1; break;}
        else B /= 2;
        cnt++;
        if(A == B) {cout << cnt; break;}
        if(B == 0) {cout << -1; break;}
    }
    return 0;
}