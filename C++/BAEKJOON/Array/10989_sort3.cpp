#include <iostream>

using namespace std;
int cnt[10001] = {0, };
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,val;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val;
        cnt[val]++;
    }

    for(int i = 1; i < 10001; i++){
        while(cnt[i] != 0){
            cout << i << '\n';
            cnt[i]--;
        }
    }
    return 0;
}