#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, val;
vector<int> LIS;


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val;
        if(LIS.empty() || LIS.back() < val)
            LIS.push_back(val);
        else {
            vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), val);
            *it = val; // iterator이 가리키는 값 덮어씌우기
        }
    }
    cout << LIS.size() << endl;
    return 0;
}