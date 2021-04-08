#include <iostream>

using namespace std;
// 배열 사이즈 크면 전역으로 선언해야 오류안남
int M, N, isPrime[1000001] = {0, };
int main(){    
    cin >> M >> N;
    for(int i = 2; i <= N; i++){
        if(isPrime[i] == -1) continue;
        for(int j = 2 * i; j <= N; j+=i)
            isPrime[j] = -1;        
    }
    for(int i = M; i <= N; i++)
        if(isPrime[i] != -1 && i != 1) cout << i << '\n';
    
    return 0;
}