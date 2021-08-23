#include <iostream>
#include <algorithm>

using namespace std;
long long N, K, ret;

// i행은 전부 i의 배수 => 개수 구하기
void find(long long start, long long end){ 
    if(start > end) return;
    long long mid = (start + end) / 2;
    long long cnt = 0;
    for(int i = 1; i <= N; i++)
        cnt += min(mid / i, N); // 중간 || 한줄
    if(cnt < K) find(mid+1, end);
    else {ret = mid; find(start, mid - 1);}
    // ex) K == 6, 7, 8 에 대해서 (N==4)
    // mid = 4로 동일, B[k]의 값은 find 함수의 mid 값에 따라 정해짐 -> B[6] = 4, B[7] = 4, B[8] = 4 
    // 조건 만족이, 최소 cnt == K, 최대 cnt > K 에서 결정됨
}

int main(){
    cin >> N >> K;
    find(1, K); 
    cout << ret;
    return 0;
}