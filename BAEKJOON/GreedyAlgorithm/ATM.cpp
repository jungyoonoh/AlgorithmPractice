#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, sum = 0, P[1000];
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> P[i];

    sort(P,P+N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            sum += P[j];
    cout << sum;
    
    return 0;
}