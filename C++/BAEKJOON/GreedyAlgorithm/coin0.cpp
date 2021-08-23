#include <iostream>

using namespace std;
int N,K,A[11]; // 동전은 모두 배수관계 만족
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    int temp = K, num = 0;
    for(int i = N-1; i>=0; i--){
        if(temp / A[i] > 0) {
            num += (temp / A[i]);
            temp %= A[i];
        }
    }
    cout << num;
        
    return 0;
}