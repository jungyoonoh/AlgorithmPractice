#include <iostream>
#include <algorithm>

using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4;
int xLeft, xRight, yTop, yBottom;
int main(){
    for(int i = 0; i < 4; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        xLeft = max(x1,x3);
        xRight = min(x2,x4);
        yBottom = max(y1,y3);
        yTop = min(y2,y4);
        
        if(xRight - xLeft > 0 && yTop - yBottom > 0) cout << 'a' << endl;
        else if(xRight - xLeft < 0 || yTop - yBottom < 0) cout << 'd' << endl;
        else if(xRight - xLeft == 0 && yTop - yBottom == 0) cout << 'c' << endl;
        else cout << 'b' << endl;
    }

    return 0;
}