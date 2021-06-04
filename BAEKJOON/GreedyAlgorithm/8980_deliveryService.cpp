#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define Village 2001
using namespace std;

int N, C, M;
int total[Village];
vector<pair<pair<int,int>, int>> list;

bool compare(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){
    if(a.first.first < b.first.first) return true;
    else if (a.first.first == b.first.first){
        if(a.first.second >= b.first.second) return true;
    }else return false;
}

int main(){
    cin >> N >> C;
    cin >> M;
    int a,b,c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        list.push_back({{a,b}, c});
    }
    memset(total, 0, sizeof(total));
    sort(list.begin(), list.end(), less<pair<pair<int,int>, int>>());
    int weight = 0, sum = 0;

    for(int i = 1; i <= N; i++){
        // 물건 내리기
        sum += total[i];
        weight -= total[i];

        // 물건 싣기
        for(int j = 0; j < list.size(); j++){
            int destination = list[j].first.second;
            if(list[j].first.first == i){
                if(weight + list[j].second <= C){
                    // 다 채울 수 있을 경우
                    weight += list[j].second;
                    total[destination] += list[j].second;
                }else {
                    // 다 못 채울때
                    int box = list[j].second; // 이번에 넣어야할 무게
                    int temp = C - weight; // 남은 용량
                    total[destination] += temp; // 먼저 넣을 수 있을만큼 넣고
                    box -= temp; // 더 넣어야할 무게 줄이고
                    for(int k = N; k >= list[j].first.second + 1; k--){
                        if(total[k] >= box){
                            // 더 넣을 무게가 목적지가 뒤쪽인 녀석보다 적다면 전부 교환
                            total[k] -= box;
                            total[destination] += box;
                            break;
                        }else {
                            total[destination] += total[k];
                            box -= total[k];
                            total[k] = 0;
                        }
                    }
                    weight = C; 
                }
            }
        }
    }
    cout << sum;

    return 0;
}