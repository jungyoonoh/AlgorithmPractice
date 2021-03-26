#include <iostream>
#include <string>

using namespace std;

int main(){
    int scale[9], fa = 0, fb = 0;
    for(int i = 1; i <= 8; i++)
        cin >> scale[i];

    for(int i = 1; i < 8; i++)
        if(scale[i] + 1 != scale[i+1]) {fa = -1; break;}    

    for(int i = 8; i > 1; i--)
        if(scale[i] - 1 != scale[i+1]) {fb = -1; break;}
        
    if(fa == 0) {cout << "ascending"; }
    else if(fb == 0) cout << "descending";
    else cout << "mixed";
    return 0;
}