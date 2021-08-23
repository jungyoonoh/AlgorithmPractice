#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> P;
int N, input, cnt = 0;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(P.empty() || P.back() > input) P.push_back(input);
        else {
            for(int i = 0; i < P.size(); i++){
                if(P.at(i) <= input){
                    P.at(i) = input;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}