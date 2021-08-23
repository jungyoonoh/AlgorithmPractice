#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;
int N, M; 

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    int val;
    for(int i = 0; i < N; i++){
        cin >> val;
        A.push_back(val);
    }    
    cin >> M;
    sort(A.begin(), A.end());
    vector<int>::iterator lower; 
    vector<int>::iterator upper; 
    for(int i = 0; i < M; i++){
        cin >> val;
        lower = lower_bound(A.begin(), A.end(), val); 
        upper = upper_bound(A.begin(), A.end(), val); 
        cout << upper - lower << " ";
    }
    return 0; 
}