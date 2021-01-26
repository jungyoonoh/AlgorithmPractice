#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int T;
string str;
string splitStr[1000];

void solve() {
    int j = 0;
    string temp;
    int len = str.length();
    for(int i = 0; i < len; i+=2) {
        temp = str;
        splitStr[j++] = temp.substr(0,2); // 0 ~ 1 idx까지 2글자씩.
        str = str.substr(2); // 0 ~ 1  2 ~ 3 
    }
    sort(splitStr, splitStr + j);

    for(int i = 0; i < j; i++){
        cout << splitStr[i];
    }
    cout << endl;
}

int main(){
    cin >> T;
    while(T--){
        cin >> str;
        solve();
    }

    return 0;
}