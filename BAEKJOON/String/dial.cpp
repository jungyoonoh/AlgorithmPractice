#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    // ABC DEF GHI JKL MNO PQRS TUV WXYZ
    int time = 0, dial[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    for(int i = 0; i < str.size(); i++)
        time += dial[str.at(i) - 'A'];
    cout << time;
    return 0;
}