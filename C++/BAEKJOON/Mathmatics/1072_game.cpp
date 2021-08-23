#include <iostream>
#include <math.h>
using namespace std;

long long X,Y,Z;
int main(){
    cin >> X >> Y;
    Z = (100 * Y / X);
    if(Z >= 99) {cout << -1; return 0;}
    int low = 0, high = 1000000000, res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int temp = (100 * (Y + mid) / (X + mid));
        if(Z >= temp){
            res = mid+1;
            low = mid+1;
        }
        else high = mid - 1;
    }
    cout << res;
    return 0;
}