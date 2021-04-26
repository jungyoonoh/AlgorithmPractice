#include <iostream>
#include <stack>

using namespace std;
stack <char> s;
string input;
bool flag = true;
int main(){
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        int sum = 0;
        if(input.at(i) == '(' || input.at(i) == '[') {s.push(input.at(i)); continue;}
        else if(input.at(i) == ')') {
            while(s.top() != '('){
                if(s.top() == -1){
                    flag = false;
                    break;
                }
                sum += s.top();
                s.pop();
            }
            if(s.top() == '(') {
                s.pop();
                s.push(2);
            }
        }
        else if(input.at(i) == ']') {
            if(s.top() == '[') {
                s.pop();
                s.push(2);
            }
        }
        if(!flag) break;
    }
    if(!s.empty() || !flag) cout << 0;
    return 0;
}