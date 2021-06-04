#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
using namespace std;

// N 극 : 0 , S극 : 1 
// 0 ~ 8 : 12시부터 11시 순 시계방향, 기어 4개
deque<int> gear[4];
int K;
vector<pair<int,int>> order;
string str[4];
bool isRotate[4];

void rotate(int gearNum, int rotateDir){
    if(rotateDir == 1){
        gear[gearNum - 1].push_front(gear[gearNum - 1].back());
        gear[gearNum - 1].pop_back();
    }else if(rotateDir == -1){
        gear[gearNum - 1].push_back(gear[gearNum - 1].front());
        gear[gearNum - 1].pop_front();
    }
}

void solve(int gearNum, int rotateDir){
    if(gearNum < 1 || gearNum > 4) return;
    // 1번 톱니의 2번 idx
    // 2번 톱니의 6번 / 2번 idx
    // 3번 톱니의 6번 / 2번 idx
    // 4번 톱니의 6번 idx 봐야함
    
    if(isRotate[gearNum - 1]) return; 

    isRotate[gearNum - 1] = true;

    if(gearNum >= 2){
        // 왼쪽을 고려
        if(gear[gearNum - 1].at(6) != gear[gearNum - 2].at(2))
            solve(gearNum - 1, rotateDir * (-1));        
    }
    if(gearNum <= 3){
        // 오른쪽을 고려
        if(gear[gearNum - 1].at(2) != gear[gearNum].at(6))
            solve(gearNum + 1, rotateDir * (-1));        
    }

    rotate(gearNum, rotateDir);    
}


int main(){
    for(int i = 0; i < 4; i++)
        cin >> str[i];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < str[i].length(); j++)
            gear[i].push_back(str[i].at(j) - '0');
    cin >> K;
    int fir, sec;
    for(int i = 0; i < K; i++){
        cin >> fir >> sec;
        order.push_back({fir, sec});
    }

    for(int i = 0; i < K; i++){
        memset(isRotate, 0, sizeof(isRotate));
        solve(order[i].first, order[i].second);
    }
    int sum = gear[0].front() * 1 + gear[1].front() * 2 + gear[2].front() * 4 + gear[3].front() * 8;
    cout << sum;
    return 0;
}