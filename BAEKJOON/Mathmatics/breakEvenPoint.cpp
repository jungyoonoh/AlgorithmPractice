#include <iostream>
#include <math.h>

using namespace std;


int main(){
    long long A,B,C;
    cin >> A >> B >> C;
    if (B >= C) cout << -1, return 0;
    else {
        long long t = A / (C-B) + 1;
        cout << t;
    }
    return 0; 
}