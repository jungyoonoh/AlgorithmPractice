#include <iostream>
#include <string.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n, sol = 0, remainder[42];
    memset(remainder,0,sizeof(remainder));
    for(int i = 0; i < 10; i++){
        cin >> n;
        remainder[n%42]++;
    }
    for(int i = 0; i < 42; i++) {
        if(remainder[i] != 0) 
            sol++;
    }
    
    cout << sol;
    return 0;
}