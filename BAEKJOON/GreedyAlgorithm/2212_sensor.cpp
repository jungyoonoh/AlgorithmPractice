#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, K, V[10000], G[10000], sum = 0;

int main(){
    cin >> N >> K;
    if(K >= N) {cout << 0; return 0;}
    for(int i = 0; i < N; i++)
        cin >> V[i];
    sort(V, V + N);
    for(int i = 0; i < N-1; i++)
        G[i] = V[i+1] - V[i];
    sort(G, G + N - 1);
    for(int i = 0; i < N - K; i++)
        sum += G[i];
    cout << sum;
    return 0;
}