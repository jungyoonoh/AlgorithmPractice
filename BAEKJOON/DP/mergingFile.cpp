#include <iostream>
#include <string.h>
#define SIZE 501
#define MAX 2147483647
using namespace std;
int T, page, file[SIZE], sum[SIZE], cache[SIZE][SIZE]; // left -> right 비용

// 구간 left - right에서 만들 수 있는 조합의 합 
int cost(int left, int right){
    if(left == right) return 0; 
    if(cache[left][right] != MAX) return cache[left][right];

    int& ret = cache[left][right];    
    if(left + 1 == right) return ret = file[left] + file[right]; // 2개일땐 합이 최소

    for(int i = left; i < right; i++){
        int lMin = cost(left, i);
        int rMin = cost(i+1, right);
        ret = min(ret, lMin + rMin);
    }

    return ret += sum[right] - sum[left - 1]; // 원소의 도합 = 최종 합 + 한 file의 값
}
void init(){
    for(int i = 1; i < SIZE; i++)
        for(int j = 1; j < SIZE; j++)  
            cache[i][j] = MAX;
}
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> page;
        sum[0] = 0;
        for(int i = 1; i <= page; i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }
        init();
        cout << cost(1, page) << '\n';
    }

    return 0;
}