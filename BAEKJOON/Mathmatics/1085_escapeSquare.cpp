#include <iostream>
#include <algorithm> 
using namespace std;

int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    int resX = min(x, w-x);
    int resY = min(y, h-y);
    cout << min(resX, resY);
    return 0;
}