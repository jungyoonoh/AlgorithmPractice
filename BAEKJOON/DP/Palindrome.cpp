#include <iostream>
#include <string.h>
#define SIZE 2001
using namespace std;

int N, arr[SIZE], M, S, E, cache[SIZE][SIZE]; // cache[a][b] -> 구간 a,b가 팰린드롬인지 여부

int palindrome(int a, int b){
    if(a > b) return 1;

    int& ret = cache[a][b];
    if(ret != -1) return ret;

    if(arr[a] == arr[b]) return ret = palindrome(a+1, b-1);
    else return 0;
}

int main(){
    cin.tie(NULL), cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
   
    memset(cache, -1, sizeof(cache));
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        palindrome(S,E) == 1 ? cout << 1 << '\n' : cout << 0 << '\n';
    }
    return 0;
}