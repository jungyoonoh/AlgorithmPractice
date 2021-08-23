#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
    int cnt = 1;
    string s;
    getline(cin,s); // 한 줄 입력받기
    if(s.empty()) {cout << "0"; return 0;}
    
    for(int i = 0; i < s.size(); i++)
        if(s.at(i) == ' ') cnt++;
        
    if(s.at(0) == ' ') cnt--;
    if(s.at(s.size() - 1) == ' ') cnt--;
    cout << cnt;

    return 0;
}