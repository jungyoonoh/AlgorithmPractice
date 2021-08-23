#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int N, w[31], C, bead[8], cache[31][15001];

void findWeight(int num, int weight){
    if(num > N) return;
    int& ret = cache[num][weight];
    if(cache[num][weight] != -1) return;
    ret = 1;
    findWeight(num + 1, weight + w[num]);
    findWeight(num + 1, weight); 
    // 새로운 추를 구슬쪽에 올릴 때, 새로운 추의 무게가 기존 추보다 크다면 추 위치 교환
    findWeight(num + 1, abs(weight - w[num]));
}

int main(){
    cin.tie(NULL), cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> w[i];
    memset(cache, -1, sizeof(cache));
    cin >> C;
    for(int i = 0; i < C; i++)
        cin >> bead[i];

    findWeight(0,0);
    for(int i = 0; i < C; i++){
        if(bead[i] > 15000) cout << "N";
        else if (cache[N][bead[i]] == 1) cout << "Y";
        else cout << "N";
        cout << '\n';
    }
    return 0; 
}