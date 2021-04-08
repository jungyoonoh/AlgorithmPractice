#include <iostream>

using namespace std;
int N, isPrime[250000] = {0, };
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    for(int i = 2; i <= 250000; i++){
        if(isPrime[i] == -1) continue;
        for(int j = 2 * i; j <= 250000; j+=i)
            isPrime[j] = -1;
    }

    while(true){
        cin >> N;
        if(N == 0) break;
        int cnt = 0;
        for(int i = N + 1; i <= 2 * N; i++)
            if(i != 1 && isPrime[i] == 0) cnt++;
        cout << cnt << '\n';
    }

    return 0;
}