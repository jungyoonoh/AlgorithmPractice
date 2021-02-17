#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int A,B,T;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << A+B << "\n";
    }
    return 0;
}