#include <iostream>

using namespace std;

// 출력할 소숫점 자리를 고정하는 방법
// cout.precision(10);

int main(){
	double a, b;
	cin >> a >> b;
    cout.precision(10);
    cout << a/b << endl;
	return 0;
}