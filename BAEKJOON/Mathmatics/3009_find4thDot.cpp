#include <iostream>

using namespace std;
int x[4], y[4];
int main(){
    int ansX, ansY;
    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }
    if(x[0] == x[1]) ansX = x[2];
    else ansX = x[0] == x[2] ? x[1] : x[0];
    if(y[0] == y[1]) ansY = y[2];
    else ansY = y[0] == y[2] ? y[1] : y[0];
    cout << ansX << " " << ansY;
    return 0;
}