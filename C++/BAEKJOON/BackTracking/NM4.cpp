#include <iostream>

using namespace std;
int N,M,arr[10];
void pick(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(depth == 0 || arr[depth - 1] <= i){
            arr[depth] = i;
            pick(depth + 1);
        }
    }
}

int main(){
    cin >> N >> M;
    pick(0);
    return 0;
}