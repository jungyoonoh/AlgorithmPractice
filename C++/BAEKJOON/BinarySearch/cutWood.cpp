#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long N, M, wood[1000000], cutHeight = 0;
bool canCut(long long value){
    long long woodSum = 0;
    for(int i = 0; i < N; i++)
        if(wood[i] - value > 0)
            woodSum += wood[i] - value;
    if(woodSum >= M) return true;
    return false;
}

void cutWood(long long start, long long end){
    if(start > end) return;
    long long mid = (start + end) / 2;
    if(canCut(mid)){
        if(cutHeight < mid)
            cutHeight = mid;
        cutWood(mid+1, end);
    } else cutWood(start, mid-1);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> wood[i];

    sort(wood, wood+N);
    cutWood(0,wood[N-1]);
    cout << cutHeight;        
    return 0;
}