#include <iostream>
#include <algorithm>

using namespace std;

bool oper(int a, int b){
    return a > b;
}

int main(){
    int sum = 0, N, rope[100001], M = -1;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> rope[i];

    sort(rope, rope+N, oper);
            
    for(int i = 0; i < N; i++)
        M = max(M, rope[i] * (i+1));

    cout << M;
    return 0;
}