#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int m = -1,n[9],idx;
    for(int i = 0; i < 9; i++){
        cin >> n[i];
        if(m < n[i]){
            m = n[i];
            idx = i;
        }
    }
    cout << m << endl;
    cout << idx + 1 << endl;

    return 0;
}