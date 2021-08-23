#include <iostream>

using namespace std;
int M,N,arr[10];
bool visited[10];
void pick(int depth){
    if(depth == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            if(depth == 0 || arr[depth - 1] < i){
                arr[depth] = i;
                pick(depth + 1);   
            }
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    pick(0);
    return 0;
}