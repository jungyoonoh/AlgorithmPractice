#include <iostream>

using namespace std;

int main(){
    int H, M;
    cin >> H >> M;
    if(M >= 45) cout << H << " " << M - 45;
    else {
        H == 0 ? cout << 23 << " " : cout << --H << " ";
        cout << M + 15;
    }        
    return 0;
}