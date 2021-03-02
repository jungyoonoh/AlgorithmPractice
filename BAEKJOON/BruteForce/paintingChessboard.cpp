#include <iostream>
#include <string>

using namespace std;
// ∏«øﬁ¬  ¿≠ƒ≠¿Ã ∞À¡§ vs »Úªˆ
int main(){
    string board[51];
    cin.tie(NULL); cin.sync_with_stdio(false);
    int N, M, m = 987654321;
    cin >> N >> M;
    for(int i = 0 ; i < N; i++)
        cin >> board[i];

    // ±‚¡ÿ¡° 
    for(int i = 0; i < N - 7; i++){
        for(int j = 0; j < M - 7; j++){
            int W = 0,B = 0,color = (i + j % 2);
            for(int k = i; k < i+8; k++){
                for(int l = j; l < j+8; l++){
                    if((k + l) % 2 == 0) board[k][l] == 'B' ? W++ : B++;
                    else board[k][l] == 'B' ? B++ : W++;                    
                }
            }
            m = min(m,W);
            m = min(m,B);
        }
    }
    cout << m;
   
    return 0;
}