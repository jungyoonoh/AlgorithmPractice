#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int cnt[100], M = -1, maxCnt = 0;
char idx = 0;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    string s;
    cin >> s;
    memset(cnt,0,sizeof(cnt));
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) >= 65 && s.at(i) <= 90)
            cnt[s.at(i) - 65]++;
        if(s.at(i) >= 97 && s.at(i) <= 122)
            cnt[s.at(i) - 97]++;
    }
    for(int i = 0; i < 26; i++)
        M = max(M,cnt[i]);
    for(int i = 0; i < 26; i++){
        if(M == cnt[i]){
            idx = i;
            maxCnt++;
        }
    }
    maxCnt == 1 ? cout << (char) (idx + 65) : cout << "?";

    return 0;
}