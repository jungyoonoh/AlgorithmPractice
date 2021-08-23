#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque <int> dq;
int K, input;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> K;
    while(K--){
        cin >> input;
        if(input == 0) dq.pop_back();
        else dq.push_back(input);
    }
    int sum = 0;
    while(!dq.empty()){
        sum += dq.back();
        dq.pop_back();
    }
    cout << sum;
    return 0;
}