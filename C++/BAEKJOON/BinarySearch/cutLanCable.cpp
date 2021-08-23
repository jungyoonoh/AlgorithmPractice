#include <iostream>
#include <algorithm>

using namespace std;

long long K, N, lan[10001], canCut = 0;
bool check(long long value){
    long long lanNum = 0;
    for(int i = 0; i < K; i++)
        lanNum += (lan[i] / value);
    
    if(lanNum >= N) return true; // 딱맞다 || 더 많이 생성 
    return false; // 모자르게 생성
}

void findSize(long long start, long long end){
    if(start > end) return; 
    long long mid = (start + end) / 2;
    if(check(mid)){
        if(canCut < mid)
            canCut = mid;
        findSize(mid + 1, end);
    } else findSize(start, mid - 1);
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> K >> N;

    for(int i = 0; i < K; i++)
        cin >> lan[i];

    sort(lan, lan + K);
    findSize(1, lan[K - 1]);
    cout << canCut;
    return 0;
}