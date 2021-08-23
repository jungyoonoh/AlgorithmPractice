#include <iostream>

using namespace std;

void checkHan(int N){
    if(N < 100) {
        cout << N;
        return;
    }
    int a,b,c,han = 99;
    for(int i = 100; i <= N; i++){
        a = i / 100; 
        b = (i / 10) % 10; 
        c = i % 10;
        if((a - b) == (b - c)) han++;
    }
    cout << han;
}

int main(){
    int N;
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    checkHan(N);
    return 0;
}