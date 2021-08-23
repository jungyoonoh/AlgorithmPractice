#include <iostream>
#include <string>
using namespace std;
string str;
bool solve(string s){
    for(int i = 0; i <= s.length() / 2; i++)
        if(s[i] != s[s.length() - i - 1]) return false;
    return true;    
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    while(true){
        cin >> str;
        if(str == "0") break;
        solve(str) == true ? cout << "yes" << '\n' : cout << "no" << '\n';
    }
    return 0;
}
