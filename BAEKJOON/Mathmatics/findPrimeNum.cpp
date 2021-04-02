#include <iostream>

using namespace std;

int main(){
    int N, prime, cnt = 0;
    cin >> N;
    while(N--){
        bool flag = true;
        cin >> prime;
        for(int i = 2; i < prime; i++)
            if(prime % i == 0) {flag = false; break;}        

        if(flag && prime != 1) cnt++;
    }
    cout << cnt;
    return 0;
}