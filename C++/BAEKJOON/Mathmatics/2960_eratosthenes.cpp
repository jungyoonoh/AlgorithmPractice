#include <iostream>
#include <string.h>
using namespace std;

int N,K,cnt = 0;
int num[1001];
int main(){
    cin >> N >> K;
    memset(num,0,sizeof(num));
    for(int i = 2; i <= N; i++){
        if(num[i] == -1) continue;
        for(int j = i; j <= N; j+=i){
            if(!num[j]) {
                num[j] = -1;
                cnt++;
                if(cnt == K) {
                    cout << j;
                    return 0;
                }
            }
        }        
    }

    return 0;
}