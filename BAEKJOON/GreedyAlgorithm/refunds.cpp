#include <iostream>

using namespace std;

int main(){
    int T, num = 0;
    cin >> T;
    int N = 1000 - T;
    if(N / 500 > 0) {num += N / 500; N %= 500;}
    if(N / 100 > 0) {num += N / 100; N %= 100;}
    if(N / 50 > 0) {num += N / 50; N %= 50;}
    if(N / 10 > 0) {num += N / 10; N %= 10;}
    if(N / 5 > 0) {num += N / 5; N %= 5;}
    num += N;
    cout << num;
    return 0;
}