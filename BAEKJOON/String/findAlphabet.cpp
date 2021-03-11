#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < 26; i++){
        bool trigger = true;
        for(int j = 0; j < s.size(); j++){
            if('a' + i == s.at(j)){
                cout << j << " ";
                trigger = false;
                break;
            }
        }
        if(trigger) cout << "-1" << " ";
    }
    return 0;    
}