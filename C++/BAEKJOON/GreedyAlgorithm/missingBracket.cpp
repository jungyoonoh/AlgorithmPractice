#include <iostream> 
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    string s, temp;
    cin >> s;
    int idx = 0, num = 0, sum = 0;
    bool state = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-'){
            temp = s.substr(idx, i - idx); 
            idx = i + 1; // 기호 다음칸 iterate
            num = stoi(temp);
            sum += state ? -num : num;
            if(s[i] == '-') state = true; // 첫 숫자 skip
        }
    }
    temp = s.substr(idx, s.size() - idx);
    num = stoi(temp);
    sum += state ? -num : num;
    cout << sum;
    return 0;
}