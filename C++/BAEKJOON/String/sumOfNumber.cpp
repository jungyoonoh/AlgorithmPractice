#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n,sum = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        sum += s.at(i) - '0';
    cout << sum;
    return 0;
}