#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M = -1, score[1000];
    double avg = 0, sum = 0;
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> score[i];
        M = max(M, score[i]);
    }
    for(int i = 0; i < N; i++)
        sum += (double) score[i] / M * 100;
    
    cout.precision(5);
    cout << sum / N;
    
    return 0;
}