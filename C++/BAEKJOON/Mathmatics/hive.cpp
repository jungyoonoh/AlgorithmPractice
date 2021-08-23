#include <iostream>

using namespace std;

int main(){
    long long N, multiply = 0, room = 0;
    cin >> N;
    for(int i = 0; ; i++){
        multiply += i;
        if(6 * multiply + 1 >= N) {
            cout << ++room;
            break;
        } else room++;
    }    
    return 0; 
}