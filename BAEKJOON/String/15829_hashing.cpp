#include <iostream>
#include <string>
#include <string.h>

#define M 1234567891
#define r 31

using namespace std;

int L;
string str;
long long temp = 1;
long long sum = 0;

int main(){
    cin >> L;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        sum += ((str.at(i) - 'a' + 1) * temp) % M;
        temp *= r;
        temp %= M;
    }
    
    cout << sum % M; 

    return 0;
}