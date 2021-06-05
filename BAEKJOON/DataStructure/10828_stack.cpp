#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

stack<int> s;
int N;
string str;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    getline(cin, str);
    int N = stoi(str);
    for(int i = 0; i < N; i++){
        getline(cin, str);
        if(str == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }else if(str == "size"){
            cout << s.size() << '\n';
        }else if(str == "empty"){
            s.empty() ? cout << "1" << '\n' : cout << "0" << '\n'; 
        }else if(str == "pop"){
            if(s.empty()) cout << -1 << '\n';
            else {cout << s.top() << '\n'; s.pop();}
        }else {
            string token = str.substr(5);
            s.push(stoi(token));
        }
    }
    return 0;
}