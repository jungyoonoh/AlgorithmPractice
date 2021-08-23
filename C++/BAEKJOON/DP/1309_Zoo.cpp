#include <iostream>
#include <string.h>
#define SIZE 100001
using namespace std;

int cage[SIZE], N;
int main(){
    cin >> N;
    memset(cage,0,sizeof(cage));    
    cage[0] = 1; cage[1] = 3;
    for(int i = 2; i <= N; i++)
        cage[i] = (2 * cage[i-1] + cage[i-2]) % 9901;
    
    cout << cage[N] % 9901;
    return 0;
}