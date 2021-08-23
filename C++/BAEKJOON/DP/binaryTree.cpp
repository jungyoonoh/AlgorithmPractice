#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#define SIZE 2100000
using namespace std;

long long tree[SIZE], path[SIZE], sum[SIZE];
int N;

int main(){
    cin >> N;
    tree[1] = 0;
    for(int i=2; i <= pow(2,N+1) - 1; i++)
        cin >> tree[i];        
    memset(path, 0, sizeof(path));
    memset(sum, 0, sizeof(sum)); 
    for(int i = pow(2, N) - 1; i >= 1; i--){
        int leftIdx = i * 2;
        int rightIdx = i * 2 + 1;
        path[i] = max(tree[leftIdx] + path[leftIdx], tree[rightIdx] + path[rightIdx]); 
        // sum[i] = sum[leftIdx] + sum[rightIdx] + tree[leftIdx] + tree[rightIdx]가 틀리는 이유
        // 값을 변경할 계획이니까 -> 계산해서 최댓값으로 지정된 값 - 차이 를 이용해야 되기 때문
        sum[i] = sum[leftIdx] + sum[rightIdx] + path[i] - path[leftIdx] + path[i] - path[rightIdx];
    }
    cout << sum[1];
    return 0;
}