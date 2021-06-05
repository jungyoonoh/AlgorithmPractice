#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int, string>> v;

int N;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    cin >> N;
    int val;
    string str;
    for(int i = 0; i < N; i++){
        cin >> val;
        cin >> str;
        v.push_back({val, str});
    }

    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++){
        cout << v.at(i).first << " " << v.at(i).second << '\n';
    }
    return 0;
}