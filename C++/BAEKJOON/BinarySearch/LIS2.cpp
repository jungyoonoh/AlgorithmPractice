#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,val;
vector<int> A;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val;
        if(A.empty() || A.back() < val)
            A.push_back(val);
        else {
            vector<int>::iterator it = lower_bound(A.begin(), A.end(), val);
            *it = val; // 대체
        }
    }
    cout << A.size();
    return 0;
}