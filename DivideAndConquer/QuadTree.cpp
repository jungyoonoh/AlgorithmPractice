#include <iostream>
#include <string>

using namespace std;
int C,idx;
string input;

string solve(){
    string temp;
    if(input[idx] != 'x'){
        temp = input[idx] == 'w' ? "w" : "b";
        idx++; // ���ȣ�� ����� == ���� ���� �Ǵ�
        return temp;
    }    
    idx++; // ���ڿ��� x�̹Ƿ�
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