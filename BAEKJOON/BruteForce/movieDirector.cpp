#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N,novelNum = 0;
    cin >> N;
    for(int i = 666; ; i++){
        if(to_string(i).find("666") != -1) novelNum++; // 시리즈 추가
        if(novelNum == N) {
            cout << i;
            break;
        }
    }
    return 0;
}