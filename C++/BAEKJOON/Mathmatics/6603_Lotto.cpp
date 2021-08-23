#include <iostream>

using namespace std;

int k, S[14];

int Lotto[6];

void solve(int idx, int cnt){
    if(cnt == 6) {
        for(int i = 0; i < cnt; i++)
            cout << Lotto[i] << " ";
        cout << endl;
        return ;
    }
    for(int i = idx; i < k; i++){
        Lotto[cnt] = S[i];
        solve(i+1, cnt+1);
    }
}


int main(){
    while(1){
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++)
            cin >> S[i];
        solve(0,0);
        cout << endl;
    }
    return 0;
}