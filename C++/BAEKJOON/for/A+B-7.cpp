#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false); // ��ǲ���ڸ��� ��� �����°� �����ִ� ����
    int A,B,T,caseNum = 1;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << "Case #" << caseNum++ <<": " << A+B << "\n";
    }
    return 0;
}