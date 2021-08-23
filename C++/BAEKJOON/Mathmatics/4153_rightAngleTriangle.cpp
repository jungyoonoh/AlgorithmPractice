#include <iostream>

using namespace std;
int a,b,c;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == b * b + a * a)) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
    return 0;
}