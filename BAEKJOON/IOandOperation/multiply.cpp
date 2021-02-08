#include <iostream>

using namespace std;

int main(){
    int a, b;
	cin >> a >> b;
    int n1,n2,n3;
    n1 = b/100; // 3
    n2 = (b - (n1 * 100)) / 10; // 8
    n3 = (b - (n1 * 100) - (n2*10)); // 5
    cout << a*n3 << endl;
    cout << a*n2 << endl;
    cout << a*n1 << endl;
    cout << a*b << endl;

    return 0;
}