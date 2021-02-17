#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    cout.setf(ios::right);
    for(int i = 1; i <= N; i++){
        cout << setw(N-i + 1);
        for(int j = 0; j < i; j++){
            cout << "*";
        }    
        cout << '\n';
    }
            
    return 0;
}