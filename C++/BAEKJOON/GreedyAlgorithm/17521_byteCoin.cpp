#include <iostream>

using namespace std;
long long N, W, coinNum, price[16] = {0, };
bool isAscend = false, isDecend = false, buy = false;
int main(){
    cin >> N >> W;

    for(int i = 0; i < N; i++)
        cin >> price[i];

    for(int i = 1; i < N; i++){
        if(price[i] > price[i-1]){
            isAscend = true;
            isDecend = false;
        }else if (price[i] < price[i-1]){
            isAscend = false;
            isDecend = true;            
        }

        if(isAscend && !buy){
            coinNum = W / price[i-1];
            W %= price[i-1];           
            buy = true;
        }
        if(isDecend && buy){
            W += coinNum * price[i-1];
            coinNum = 0;
            buy = false;
        }
    }

    cout << W + coinNum * price[N-1];
    
    return 0;
}