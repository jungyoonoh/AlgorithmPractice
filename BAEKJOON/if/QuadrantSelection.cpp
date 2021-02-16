#include <iostream>

using namespace std;
// x,y; 1 : positive / 0 : negative
int dir[2][2] = {{3,2},{4,1}};
int main(){
    int x,y;
    cin >> x >> y;
    int dirX = x > 0 ? 1 : 0;   
    int dirY = y > 0 ? 1 : 0;
    cout << dir[dirX][dirY];   
    return 0;
}