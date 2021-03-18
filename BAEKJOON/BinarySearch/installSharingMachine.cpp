#include <iostream>
#include <algorithm>
using namespace std;

long long N, C, house[200000], dist = 0;
bool canInstall(long long value){ 
    // 간격 value로 설치
    int idx = 0, installedNum = 1; 
    for(int i = 1; i < N; i++){
        if(house[idx] + value <= house[i]){
            installedNum++;
            idx = i;
        }
    }
    if(installedNum >= C) return true;
    return false;
}

void findSpot(long long start, long long end){
    if(start > end) return;
    long long mid = (start + end) / 2;
    if(canInstall(mid)){
        if(dist < mid)
            dist = mid;
        findSpot(mid + 1, end);
    } else findSpot(start, mid - 1);
}

int main(){
    cin >> N >> C;
    for(int i = 0; i < N; i++)
        cin >> house[i];

    sort(house, house + N);
    findSpot(1, house[N - 1]);
    cout << dist;
    return 0;
}