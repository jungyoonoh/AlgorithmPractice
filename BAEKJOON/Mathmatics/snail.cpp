#include <iostream>

using namespace std;

int main(){
    long long A,B,V;
    cin >> A >> B >> V;
    long long T = (V-A) / (A-B);
    if((V-A) % (A-B) == 0) cout << T+1;
    else cout << T+2;
    return 0;
}