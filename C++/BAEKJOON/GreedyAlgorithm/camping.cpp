#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int L,P,V, Case = 1;
    while (true) {    
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;
        int day = (V / P) * L;
        int rest = (V % P);
        rest <= L ? day += rest : day += L;
        cout << "Case " << Case++ << ": " << day << '\n';    
    }
    return 0;
}