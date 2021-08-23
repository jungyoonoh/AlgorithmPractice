#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> t;
string str;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    while(1){
        bool flag = false;
        getline(cin, str);
        if(str.size() == 1 && str.at(0) == '.') break;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '[')
                t.push(str[i]);            
            else if(str[i] == '(')
                t.push(str[i]);
            else if(str[i] == ']'){
                if(t.empty() || t.top() != '[') {cout << "no" << endl; flag = true; break;}
                else t.pop();
            }else if(str[i] == ')'){
                if(t.empty() || t.top() != '(') {cout << "no" << endl; flag = true; break;}
                else t.pop();
            }else continue;
        }
        if(!flag){
            if(t.empty()) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        
        while(!t.empty()) t.pop();
    }
    return 0;
}