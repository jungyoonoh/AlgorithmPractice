#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

string a,b;
int table[1002][1002];

int solve(){
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    return table[a.size()][b.size()];
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> a >> b;
    memset(table, 0, sizeof(table));
    cout << solve();
    return 0;
}