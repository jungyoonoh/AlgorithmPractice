#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M, minimum = 2147483647, sum = 0;
    cin >> M >> N;
    for (int i = M; i <= N; i++){
        if(i == 1) continue;
        bool flag = true;
        for (int j = 2; j < i; j++){
            if ((i % j) == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            sum += i;
            minimum = min(minimum, i);
        }
    }
    if(minimum == 2147483647) cout << -1 << endl;
    else{
        cout << sum << '\n';
        cout << minimum << '\n';
    }
    return 0;
}