#include <iostream>
#include <stack>

using namespace std;

stack <char> s;
string input;
bool flag = true;
int sum = 0, temp = 1;
int main(){
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        if(input.at(i) == '(') {
            s.push(input.at(i));
            temp *= 2;
        }
        else if(input.at(i) == '[') {
            s.push(input.at(i));
            temp *= 3;
        }
        else if(input.at(i) == ')') {
            if(s.empty() || s.top() != '('){
                flag = false;
                break;
            }
            else{
                if(input.at(i-1) == '(') sum += temp;
                temp /= 2;
                s.pop();
            }
        }
        else if(input.at(i) == ']') {
            if(s.empty() || s.top() != '['){
                flag = false;
                break;
            }
            else{
                if(input.at(i-1) == '[') sum += temp;
                temp /= 3;
                s.pop();
            }
        }
    }
    if(!s.empty() || !flag) cout << 0;
    else cout << sum;
    return 0;
}