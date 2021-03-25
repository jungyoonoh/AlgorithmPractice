#include <iostream>

using namespace std;

int main(){
    int X, sum = 0;
    cin >> X;
    if(X == 1) {cout << "1/1"; return 0;}
    for(int i = 0; ; i++){
        sum += i;
        if(sum >= X){
            int temp = sum % X;
            i % 2 == 0 ? cout << i - temp << "/" << 1 + temp : cout << 1 + temp << "/" << i - temp;
            break;
        }
    }
    return 0;
}