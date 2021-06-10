#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    pair<int, int> temp;
    for(int i = 0; i < N; i++){
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++)
        cout << v[i].first << " " << v[i].second << '\n';
    
    return 0;
}