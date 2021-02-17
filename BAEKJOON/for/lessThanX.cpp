#include <iostream>

using namespace std;
int A[10001];
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int X,N;
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] < X) cout << A[i] << " ";     
    }
    return 0;
}