#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b){
    if(a.size()==b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    int N;
    cin >> N;
    vector<string> str;
    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        str.push_back(s);
    }

    sort(str.begin(), str.end());
    sort(str.begin(), str.end(), compare);
    str.erase(unique(str.begin(), str.end()),str.end());

    for(int i = 0; i < str.size(); i++)
        cout << str[i] << '\n';

    return 0;
}