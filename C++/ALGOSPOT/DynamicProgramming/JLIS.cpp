#include <iostream>
#include <algorithm>
#include <cstring>
#define MIN -2147483649
using namespace std;

int A[100], B[100]; // 수열 a, 수열 b
int cache[101][101];
int n, m; // A와 B의 길이

int findJLis(int aIdx, int bIdx){
    int& ret = cache[aIdx+1][bIdx+1];

    if (ret != -1)
        return ret;

    ret = 0;
    long long a = (aIdx == -1 ? MIN : A[aIdx]);
    long long b = (bIdx == -1 ? MIN : B[bIdx]);
    long long now = max(a, b);
    // Q. min -> 수열 간격이 촘촘해야 더 길지 않는가 ?
    // A. for문의 if문에서 다음 lis의 원소가 될 수 있음을 파악 
    // 비교 대상을 갱신하기 위한 작업을 한거임
    // maxElement는 결국엔 현재 가리키고 있는 값을 참조하기 위한 절차

    for (int i = aIdx + 1; i < n; i++)
        if (now < A[i])
            ret = max(ret, findJLis(i, bIdx) + 1);
 
    for (int i = bIdx + 1; i < m; i++)
        if (now < B[i])
            ret = max(ret, findJLis(aIdx, i) + 1);
            
    return ret;
}

void init(){
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            cache[i][j] = -1;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        init();
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> A[i];

        for(int i = 0; i < m; i++)
            cin >> B[i];
         
        cout << findJLis(-1,-1) << endl;
    }
    return 0;
}