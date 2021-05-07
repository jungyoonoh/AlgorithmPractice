#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
bool isZero = false, isOne = false;
int zeroCnt = 0, oneCnt = 0;
int main(){
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        if(!isZero && str.at(i) == '0') {
            isZero = true;
            isOne = false;
            zeroCnt++;
        } else if(!isOne && str.at(i) == '1'){
            isZero = false;
            isOne = true;
            oneCnt++;
        }
    }

    cout << min(zeroCnt, oneCnt);

    return 0;
}