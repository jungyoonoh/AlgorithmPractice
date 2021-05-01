#include <iostream>

using namespace std;

int N,A,B;
int main(){
    cin >> N >> A >> B;
    int cnt = 0;
    while(1){       
        A -= A / 2;
        B -= B / 2;
        cnt++;
        if(A == B) break;
    }
    cout << cnt;
    return 0;    
}