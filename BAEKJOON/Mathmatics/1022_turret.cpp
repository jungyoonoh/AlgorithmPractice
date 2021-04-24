#include <iostream>
using namespace std;
long long x1, y1, r1, x2, y2, r2, TC;
int main(){
    cin >> TC;
    while(TC--){
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        long long dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        long long sum = (r1 + r2) * (r1 + r2);
        long long min = abs(r1 - r2) * abs(r1 - r2);
        if(sum > dist && dist > min) cout << 2 << endl;
        else if (dist == sum || ((dist == min) && dist != 0)) cout << 1 << endl;
        else if (dist > sum || dist < min) cout << 0 << endl;
        else if (dist == 0) 
            if (r1 == r2) cout << -1 << endl;
            else cout << 0 << endl;
    }
    return 0;
}