#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

int N;
int d[500001];
int cnt[8001];
int maxVal = -4001, minVal = 4001;
long long sum = 0;

int main(){
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < N; i++){
        cin >> d[i];
        sum += d[i];
        cnt[d[i] + 4000]++;
    }

    sort(d, d+N);
    
    int t = -1, idx = -1;
    for(int i = 0; i <= 8000; i++){
        if(t < cnt[i]){
            t = cnt[i];
            idx = i;
        }
    }

    for(int i = idx + 1; i <= 8000; i++){
        if(cnt[i] == t){
            idx = i;
            break;
        }
    }

    cout << round(sum / (double)N) << endl;
    cout << d[(N-1)/2]<< endl;
    cout << idx - 4000 << endl;
    cout << d[N-1] - d[0] << endl;
    return 0;
}