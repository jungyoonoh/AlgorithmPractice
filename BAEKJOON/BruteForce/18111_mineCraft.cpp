#include <iostream>
#include <algorithm>
using namespace std;

// 1. 현재 높이가 전부 같은지 여부
// 2. 땅의 높이를 전부 min ~ max 로 만들어보는 try를 할 것
// 3. 각각의 시간을 재서 비교할 것
// 4. 인벤토리 개수도 고려해봐야함
// 블록 제거는 2초가 걸리고
// 블록 쌓는건 1초가 걸림

int N,M,B; // 가로 세로 인벤의 벽돌 갯수
int map[501][501];
int minBound = 257, maxBound = -1;
pair<int, int> ans; // 시간과 땅의 높이를 저장


void solve(int height){
    int time = 0;
    
    // 회수하고 쌓고 가 가능한지부터 파악해야함 현재 높이를 맞추기 위해서
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int val = height - map[i][j]; 
            if(val == 0) continue;
            else cnt += val;
            // else if(val > 0){
            //     cnt += val; // 쌓으니까 블럭 소모                
            // }else if(val < 0){
            //     cnt += val; // 블럭을 줄여야 하니 인벤토리의 블록 증가
            // }
        }
    }
    
    // 못하는 경우 제외
    if(B - cnt < 0) return;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int val = height - map[i][j]; 
            if(val == 0) continue;
            else if(val > 0){
                time += abs(val); // 쌓기               
            }else if(val < 0){
                time += abs(val * 2); // 인벤토리에 넣기
            }
        }
    }
    if(ans.first > time){
        ans.first = time;
        ans.second = height;
    }else if (ans.first == time){
        ans.second = height;
    }
    return ;
}

int main(){
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            minBound = min(minBound, map[i][j]);
            maxBound = max(maxBound, map[i][j]);
        }
    }

    ans.first = 100000000;
    ans.second = -1;
    for(int i = minBound; i <= maxBound; i++){
        solve(i);
    }

    cout << ans.first << " " << ans.second;
    
    return 0;
}