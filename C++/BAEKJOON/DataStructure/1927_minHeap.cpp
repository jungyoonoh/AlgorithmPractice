#include <iostream>
#include <queue>

using namespace std;

int N, x;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x != 0)
            pq.push(x);
        else if(pq.size() == 0) cout << 0 << '\n';
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}