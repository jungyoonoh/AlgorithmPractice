#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N, K;
string numToStr;
deque<char> dq;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N >> K;
    cin >> numToStr;

    for(int i = 0; i < N; i++){
        while(!dq.empty() && K != 0 && dq.back() < numToStr[i]){
            dq.pop_back();
            K--;
        }
        dq.push_back(numToStr[i]);
    }

    while(K != 0){
        dq.pop_back();
        K--;
    }

    for(int i = 0; i < dq.size(); i++)
        cout << dq[i];
    
    return 0;
}