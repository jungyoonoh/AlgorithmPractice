#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int N,x;

struct compare{
    bool operator()(int a, int b){
        // 우선순위 큐에서 작은값을 위로 올리기 위함
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    priority_queue <int, vector<int>, compare> pq;
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