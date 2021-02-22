#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<vector<int>> meeting;


bool compare(const vector<int>& v1, const vector<int>& v2){
    if(v1[1] != v2[1]) return v1[1] < v2[1];
    else return v1[0] < v2[0]; // 시간이 같은 경우에 우선순위를 배정해야함
}

int main(){
    cin >> N;
    int start,end;
    for(int i = 0; i < N; i++){
        cin >> start >> end;
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        meeting.push_back(temp);
    }
    sort(meeting.begin(), meeting.end(), compare);
    int endPoint = -1, ans = 0;
    for(int i = 0; i < N; i++){
        if(meeting[i][0] >= endPoint){
            ans++;
            endPoint = meeting[i][1];
        }
    }
    cout << ans;

    return 0;
}