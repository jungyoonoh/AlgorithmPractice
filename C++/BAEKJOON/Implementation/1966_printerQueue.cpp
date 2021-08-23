#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int TC, N, M, priority[100];
deque<pair<int,int>> dq;
priority_queue<int> pq;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            cin >> priority[i];
            pair<int, int> temp;
            temp.first = i;
            temp.second = priority[i];
            dq.push_back(temp);
            pq.push(priority[i]);
        }
        int sequence = 1;
        while(!dq.empty()){
            pair<int, int> temp = dq.front();
            if(pq.top() == temp.second){
                if(temp.first == M){
                    cout << sequence << endl;                
                    break;
                }
                sequence++;                
                pq.pop();
            }
            dq.push_back(temp);
            dq.pop_front();
        }

        while(!pq.empty()) pq.pop();
        dq.clear();
    }
    return 0;
}