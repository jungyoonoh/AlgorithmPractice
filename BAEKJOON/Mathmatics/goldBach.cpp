#include <iostream>

using namespace std;
int T,n, isPrime[10001] = {0, };
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    for(int i = 2; i <= 10000; i++){
        if(isPrime[i] == -1) continue;
        for(int j = 2 * i; j <= 10000; j+=i)
            isPrime[j] = -1;
    }
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = n / 2; i < n - 1; i++){
            int j = n - i;
            if(isPrime[i] != -1 && isPrime[j] != -1) {
                cout << j << " " << i << '\n';
                break;                
            }
        }
    }
    return 0;
}