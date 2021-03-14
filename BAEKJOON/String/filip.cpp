#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c = stoi(a);
    int d = stoi(b);
    c > d ? cout << c : cout << d;
    return 0;
}