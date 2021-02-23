#include <iostream>
#include <string.h>
using namespace std;
int A,B,C;
int num[10];
int main(){
    cin >> A >> B >> C;
    long long mul = A*B*C;
    for(int i = mul; i != 0; i/=10)
        num[i%10]++;
    
    for(int i = 0; i < 10; i++)
        cout << num[i] << endl;
    return 0;
}