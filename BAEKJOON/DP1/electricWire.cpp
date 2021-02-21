#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, range = 0, fmax = -1, rmax = -1, M;
int wire[501]; // [a] = b  -> a,b ¿¬°á
int fdp[501];
int rdp[501];

int solve(){
    for(int i = 1; i <= range; i++){
        int maxPos = 0, maxRpos = 0;
        for(int j = 1; j < i; j++){
            if((wire[j] != -1) && (wire[i] != -1) && (wire[j] < wire[i])) maxPos = max(maxPos, fdp[j]);
            if((wire[range - j + 1] != -1) && (wire[range - i + 1] != -1) && (wire[range - j + 1] < wire[range - i + 1])) maxRpos = max(maxRpos, rdp[j]);
        }
        fdp[i] = maxPos + 1;
        rdp[i] = maxRpos + 1;
    }
    for(int i = 1; i <= range; i++){
        fmax = max(fmax, fdp[i]);
        rmax = max(rmax, rdp[i]);
    }    
    M = max(fmax, rmax);    
    return N - M;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b;
    memset(wire,-1,sizeof(wire));
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        wire[a] = b;
        range = max(range, max(a,b));
    }
    cout << solve();
    return 0;
}