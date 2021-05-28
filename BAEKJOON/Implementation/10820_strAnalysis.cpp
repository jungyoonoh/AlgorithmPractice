#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string str;

int cnt[4]; // 소문자 대문자 숫자 공백

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    for(int j = 0; j < 100; j++){
        getline(cin, str);
        if(str.length() == 0) break;
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < str.size(); i++){
            if(str.at(i) <= 'z' && str.at(i) >= 'a') cnt[0]++;
            else if(str.at(i) <= 'Z' && str.at(i) >= 'A') cnt[1]++;
            else if(str.at(i) <= '9' && str.at(i) >= '0') cnt[2]++;
            else if(str.at(i) == ' ') cnt[3]++;
        }
        for(int i = 0; i < 4; i++)
            cout << cnt[i] << " ";
        cout << endl;
    }
    return 0;
}