#include <iostream>

using namespace std;

long long A, B;

long long solve(long long a, long long b){
    while(b != 0){
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    cin >> A >> B;
    for(int i = 0; i < solve(A,B); i++)
        cout << 1;
    return 0;
}