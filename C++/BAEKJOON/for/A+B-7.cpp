#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false); // 인풋하자마자 결과 나오는거 막아주는 설정
    int A,B,T,caseNum = 1;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << "Case #" << caseNum++ <<": " << A+B << "\n";
    }
    return 0;
}