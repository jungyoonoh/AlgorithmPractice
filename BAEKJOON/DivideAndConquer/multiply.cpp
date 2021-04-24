#include <iostream>

using namespace std;

long long A,B,C;
long long solution(long long a, long long b){
    if(b == 0) return 1;
    long long temp = solution(a, b / 2);
    if(b % 2 == 0) return (temp * temp) % C;
    if(b % 2 == 1) return (((temp * temp) % C) * A) % C;
}

int main(){
    cin >> A >> B >> C;
    cout << solution(A % C, B);
    return 0;
}