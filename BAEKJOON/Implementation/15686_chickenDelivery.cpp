#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, chickenCnt = 0, ret = 99999999;
int map[50][50];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
vector<pair<int,int>> checked;
bool isSelected[13];

void calcDist(){
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        int dist = 2500;
        for(int j = 0; j < chicken.size(); j++){
            if(isSelected[j])
                dist = min(dist, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
        }
        sum += dist;
    }
    ret = min(ret, sum);
}

void selectStore(int idx, int cnt){
    if(cnt == M){
        calcDist();
        return;
    }
    
    for(int i = idx; i < chicken.size(); i++){
        if(!isSelected[i]){
            isSelected[i] = true;
            selectStore(i + 1, cnt + 1);
            isSelected[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back({i,j}); // y, x
            if(map[i][j] == 2) chicken.push_back({i,j});
        }
    }
    memset(isSelected, 0, sizeof(isSelected));
    selectStore(0, 0);
    cout << ret;

    return 0;
}