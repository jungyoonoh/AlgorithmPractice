#include <iostream>
#include <algorithm>

using namespace std;

// 1 1 2 3 6 7 30 
int N, balance[1001], sum = 0;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> balance[i];

    sort(balance, balance+N);

    for(int i = 0; i < N; i++){
        if(balance[i] <= sum + 1)
            sum += balance[i];
        else break;
    }
    cout << sum + 1;

    return 0;
}