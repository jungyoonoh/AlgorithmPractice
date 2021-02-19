#include <iostream>
#include <algorithm>

using namespace std;

int A[1000001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    sort(A,A+n);
    cout << A[0] << " " << A[n-1];
    return 0;
}