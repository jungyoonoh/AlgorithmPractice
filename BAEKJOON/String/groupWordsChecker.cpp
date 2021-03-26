#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int N, words[26];

int main(){
    string str;
    cin >> N;
    int cnt = N;
    while (N--){
        cin >> str;
        memset(words, -1, sizeof(words));
        for (int i = 0; i < str.size(); i++){
            if (words[str.at(i) - 'a'] != -1) {cnt--; break;}
            else {
                if(i != str.size() - 1)
                    while(str.at(i) == str.at(i+1)){ 
                        if(i+1 == str.size() - 1) { i++; break;}
                        i++;
                    }                                 
                words[str.at(i) - 'a'] = 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}