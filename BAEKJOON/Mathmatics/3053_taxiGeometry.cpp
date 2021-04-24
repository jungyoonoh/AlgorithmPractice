#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;
int R;
double uclid, taxi;
int main(){
    cin >> R;
    uclid = R*R*M_PI;
    taxi = 4 * R * R / 2;
    cout << fixed;
    cout.precision(6);
    cout << uclid << endl;
    cout << taxi;
    return 0;
}