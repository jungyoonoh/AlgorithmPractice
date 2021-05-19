#include <iostream>
#include <string>

using namespace std;
string str;
int L = 0, R = 0;
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(i < str.size() / 2) L += str.at(i) - '0';
        else R += str.at(i) - '0';
    }
    if(L == R) cout << "LUCKY";
    else cout << "READY";
    return 0;
}