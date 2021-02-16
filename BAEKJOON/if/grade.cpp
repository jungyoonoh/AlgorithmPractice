#include <iostream>

using namespace std;
// switch case문이 빠른데 어케해야 쓸 수 있을까
int main(){
    int score;
    cin >> score;
    switch (score/10)
    {
    case 10:
    case 9: cout << "A"; break;
    case 8: cout << "B"; break;
    case 7: cout << "C"; break;
    case 6: cout << "D"; break;
    default: cout << "F"; break;
    }
    return 0;
}