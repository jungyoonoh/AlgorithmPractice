#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int card, N, sum = 0;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;    
    for(int i = 0; i < N; i++){
        cin >> card;
        pq.push(card);
    }
    int A,B;    
    while(pq.size() != 1){
        A = pq.top();
        pq.pop();
        B = pq.top();
        pq.pop();
        sum += A+B;
        pq.push(A+B);
    }
    cout << sum;
    return 0;
}