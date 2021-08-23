#include <iostream>
#include <stack>
#include <string>

using namespace std;
int N;
string str;
stack<char> s;
int main(){ 
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;        
        bool flag = false;
        for(int j = 0; j < str.size(); j++){
            if(str.at(j) == '(') s.push(str.at(j));
            else {
                if(s.empty()) {cout << "NO" << '\n'; flag = true; break;}
                else {
                    s.pop();
                }
            }
        }
        if(!flag){
            if(s.empty()) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        while(!s.empty()) s.pop();
    }
    return 0;
}