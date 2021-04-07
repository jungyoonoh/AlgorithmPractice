#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int>& v1, const pair<int,int>& v2){
    return v1.first < v2.first;
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int T,N, s1, s2;
    cin >> T;
    while(T--){
        int cnt = 1;
        cin >> N;
        vector<pair<int,int>> recruit;
        for(int i = 0; i < N; i++){
            cin >> s1 >> s2;
            recruit.push_back(make_pair(s1,s2));
        }
        sort(recruit.begin(), recruit.end());
        int comp = recruit[0].second;
        for(int i = 0; i < N - 1; i++){
            if() {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}