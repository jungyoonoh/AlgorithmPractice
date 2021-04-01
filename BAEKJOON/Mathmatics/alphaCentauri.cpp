#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    long long T, x, y;
    cin >> T;
    while(T--){
        long long sum = 0, turn = 0;
        cin >> x >> y;
        for(int i = 1; ; i++){
            sum += i; turn++;
            if(sum >= y - x) {cout << turn << '\n'; break;}
            sum += i; turn++;
            if(sum >= y - x) {cout << turn << '\n'; break;}
        }
    }
    return 0;
}