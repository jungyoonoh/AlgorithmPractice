#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int prime[1000001], N;
bool flag = true;
void solve(){
    if(N % 2 == 1){
        N -= 5;
        for(int i = 2; i <= N - 2; i++){
            if(prime[i] == -1 && prime[N-i] == -1){
                cout << "2 3 " << i << " " << N-i;
                return;
            }
        }
    }   
    else {
        N -= 4;
        for(int i = 2; i <= N - 2; i++){
            if(prime[i] == -1 && prime[N-i] == -1){
                cout << "2 2 " << i << " " << N-i;
                return;
            }
        }
    }
    cout << -1;
    return;
}


int main(){
    cin >> N;
    memset(prime,-1,sizeof(prime));
    if(N < 8) {cout << -1; return 0;}
    for(int i = 2; i <= N; i++){
        if(prime[i] == 0) continue;
        for(int j = 2*i; j <= N; j+=i)
            prime[j] = 0;        
    }

    solve();
    return 0;
}