#include <iostream>
#include <string>

using namespace std;
int C,idx;
string input;

string solve(){
    string temp;
    if(input[idx] != 'x'){
        temp = input[idx] == 'w' ? "w" : "b";
        idx++; // 재귀호출 종료시 == 다음 문자 판단
        return temp;
    }    
    idx++; // 문자열이 x이므로
    string LU = solve();
    string RU = solve();
    string LD = solve();
    string RD = solve();
    return "x"+LD+RD+LU+RU;
}

int main() {
    cin >> C;
    while(C--){
        idx = 0;
        cin >> input;
        cout << solve() << endl;
    }
    return 0;
}