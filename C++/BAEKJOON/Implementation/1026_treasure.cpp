#include <iostream>
#include <algorithm>

using namespace std;
int N, A[100], B[100],S = 0;

bool compare(int& a, int& b){
    return a > b;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A+N);
    sort(B, B+N, compare);
    for(int i = 0; i < N; i++)
        S += A[i] * B[i];
    
    cout << S;
    
    return 0;
}