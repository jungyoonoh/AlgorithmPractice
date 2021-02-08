#include <iostream>

using namespace std;

int c = 0;
int d = 100;

int sum(int n){
    int ret = 0;
    for(int i = 1; i<=n; i++)
        ret += i;
    return ret;
}

int recursiveSum(int n){
    if (n == 1) return 1; // 더이상 쪼개지지 x
    return n + recursiveSum(n-1); // n ~ 1까지 더하는형태
}

int main()
{
    int input;
    cin >> input;
    cout << sum(input) << endl;
    cout << recursiveSum(input) << endl;

    return 0;
}