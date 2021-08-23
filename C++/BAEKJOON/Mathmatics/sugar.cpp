#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;

int main(){
    int N, m = MAX;
    cin >> N;
    int fiveN = N / 5; // 개수
    for(int i = fiveN; i >= 0; i--){
        if((N - i * 5) % 3 == 0)
            m = min(m, ((N - i * 5) / 3) + i);
    }
    m == MAX ? cout << -1 : cout << m;
    
    return 0;
}